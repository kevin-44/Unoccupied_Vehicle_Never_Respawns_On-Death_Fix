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

// ** INCLUDES

#include <a_samp>
#include <sscanf2>
#include <zcmd>
#include <unoccupied_vehicle_never_respawns_on_death_fix>

// ** MAIN

main()
{
	print("Loaded \"unoccupied_vehicle_never_respawns_on_death_fix_example.amx\".");
}

// ** CALLBACKS

public OnGameModeInit()
{
	AddStaticVehicleEx(560, 132.1675, -91.1419, 1.1661, 268.9395, -1, -1, 10); // Sultan
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

// ** COMMANDS

CMD:zero(playerid, params[])
{
	new vehicle_id;
	if(sscanf(params, "i", vehicle_id))
	{
		SendClientMessage(playerid, -1, "Usage: /zero (vehicle id)");
	}
	else
	{
		SetVehicleHealth(vehicle_id, 0.0);
	}
	return 1;
}