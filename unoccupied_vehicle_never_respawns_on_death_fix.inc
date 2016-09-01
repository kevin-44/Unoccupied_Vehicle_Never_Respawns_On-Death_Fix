/*
	Unoccupied Vehicle Never Respawns On-Death Fix ~ Kevin-Reinke

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _uvnrodf_included
	#endinput
#endif

#define _uvnrodf_included

// ** VARIABLES

// *** GLOBAL VARIABLES

// **** TIMERS

static ptmRespawnUnoccupiedVehicle[MAX_VEHICLES];

// ** HOOKS

// *** SetVehicleHealth

stock Hook_SetVehicleHealth(vehicleid, Float:health)
{
	KillTimer(ptmRespawnUnoccupiedVehicle[vehicleid]);
	
	if(health < 250.0)
	{
		ptmRespawnUnoccupiedVehicle[vehicleid] = SetTimerEx("RespawnUnoccupiedVehicle", 13000, false, "i", vehicleid);
	}
	return SetVehicleHealth(vehicleid, health);
}

#if defined _ALS_SetVehicleHealth
	#undef SetVehicleHealth
#else
	#define _ALS_SetVehicleHealth
#endif

#define SetVehicleHealth Hook_SetVehicleHealth

// ** CALLBACKS

public OnVehicleSpawn(vehicleid)
{
	KillTimer(ptmRespawnUnoccupiedVehicle[vehicleid]);

	#if defined uvnrodf_OnVehicleSpawn
		return uvnrodf_OnVehicleSpawn(vehicleid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnVehicleSpawn
	#undef OnVehicleSpawn
#else
	#define _ALS_OnVehicleSpawn
#endif

#define OnVehicleSpawn uvnrodf_OnVehicleSpawn

#if defined uvnrodf_OnVehicleSpawn
	forward uvnrodf_OnVehicleSpawn(vehicleid);
#endif

// ** FUNCTIONS

forward RespawnUnoccupiedVehicle(vehicle_id);
public RespawnUnoccupiedVehicle(vehicle_id)
{
	SetVehicleToRespawn(vehicle_id);
	return 1;
}