/*
    File: fn_seatbeltOn.sqf
    Author: Ethan (XaLaForo)
*/

class playerHUD {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";

    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    
    //--- OBJECTS
    objects[] = {};
    
    //--- CONTROLS
    controls[] = {
        RscDisplayHealthBackground,
        RscDisplayHealthProgress,
        RscDisplayHealthText,
        RscDisplayWaterBackground,
        RscDisplayWaterProgress,
        RscDisplayWaterText,
        RscDisplayHungerBackground,
        RscDisplayHungerProgress,
        RscDisplayHungerText,
        RscDisplayCashAmount
    };

		class RscDisplayHealthBackground
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.96666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "";
			colorBackground[] = {0.2,0.2,0.2,0.3};
			colorText[] = {0.6118,0.0902,0.0314,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayHealthProgress
		{
			type = 8;
			idc = 2201;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.96666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			colorBar[] = {0.2,0.2,0.2,1};
			colorFrame[] = {0,0,0,1};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			
		};
		class RscDisplayHealthText
		{
			type = 0;
			idc = 2205;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.96666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "HEALTH: 100%";
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayWaterBackground
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.94166667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "";
			colorBackground[] = {0.2,0.2,0.2,0.3};
			colorText[] = {0.6118,0.0902,0.0314,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayWaterProgress
		{
			type = 8;
			idc = 2202;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.94166667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			colorBar[] = {0.2,0.2,0.2,1};
			colorFrame[] = {0,0,0,1};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			
		};
		class RscDisplayWaterText
		{
			type = 0;
			idc = 2204;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.94166667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "WATER: 100%";
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayHungerBackground
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.91666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "";
			colorBackground[] = {0.2,0.2,0.2,0.3};
			colorText[] = {0.6118,0.0902,0.0314,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayHungerProgress
		{
			type = 8;
			idc = 2200;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.91666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			colorBar[] = {0.2,0.2,0.2,1};
			colorFrame[] = {0,0,0,1};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			
		};
		class RscDisplayHungerText
		{
			type = 0;
			idc = 2203;
			x = safeZoneX + safeZoneW * 0.8453125;
			y = safeZoneY + safeZoneH * 0.91666667;
			w = safeZoneW * 0.1484375;
			h = safeZoneH * 0.02222223;
			style = 0;
			text = "HUNGER: 100%";
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class RscDisplayCashAmount
		{
			type = 0;
			idc = 2206;
			x = safeZoneX + safeZoneW * 0.85375;
			y = safeZoneY + safeZoneH * 0.888;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.029;
			style = 0+1;
			text = "£0";
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		
};

