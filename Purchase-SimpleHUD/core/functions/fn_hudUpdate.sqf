#include "..\..\script_macros.hpp"
/*
	File: fn_hudUpdate.sqf
	Author: XaLaForo

	Description:
	Updates the HUD when it needs to.
*/

//--- Disable Serialization
disableSerialization;

//--- Get Display Params
if(isNull LIFEdisplay) then {[] call life_fnc_hudSetup;};

//--- Progress Definers
LIFEctrl(2200) progressSetPosition (1 / (100 / life_hunger));
LIFEctrl(2201) progressSetPosition (1 - (damage player));
LIFEctrl(2202) progressSetPosition (1 / (100 / life_thirst));

//--- Text Definers
LIFEctrl(2203) ctrlSetText format ["FOOD: %1%2", life_hunger, "%"];
LIFEctrl(2204) ctrlSetText format ["THIRST: %1%2", life_thirst, "%"];
LIFEctrl(2205) ctrlSetText format ["HEALTH: %1%2", round(100 - (damage player * 100 )), "%"];
LIFEctrl(2206) ctrlSetStructuredText parseText format ["£%1", [life_cash] call life_fnc_numberText];