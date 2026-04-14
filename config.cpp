class CfgPatches {
	class Bro_Modular_Ship {
		name = "Modular Ship Interior [Bromine]";
		author = "Bromine";
		url = "https://steamcommunity.com/id/Brominum/";
		requiredAddons[] = {"A3_Data_F_Decade_Loadorder"};
		requiredVersion = 1.60;
	};
};
class CfgEditorCategories {
	class Bro_MSHIP_EdCat {
		displayName = "Modular Ship Parts [Bromine]";
	};
};
class CfgEditorSubcategories {
	class Bro_MSHIP_EdSubcat {
		displayName = "Ship Interior";
	};
};
class CfgFunctions  {
	class bro  {
		class bro_mship {
			file = "\Bro_Modular_Ship\functions";
			class snap_mship{};
			class sign_mship{};
		};
	};
};
class CfgVehicles {
	class HouseBase;
	class House_f: HouseBase {
		class EventHandlers;
	};
	class Land_Bro_MSHIP_Base: House_f {
		scope = 0;
		scopeCurator = 0;
		author = "Bromine";
		editorCategory = "Bro_MSHIP_EdCat";
		editorSubcategory = "Bro_MSHIP_EdSubcat";
		icon = "Bro_Modular_Ship\icon_ca.paa";
		destrType = "DestructNo";
		mapSize = 5;
		keepHorizontalPlacement = 1;
		numberOfDoors = 0;
		class EventHandlers: EventHandlers {
			dragged3DEN = "_this call bro_fnc_snap_mship;";
			registeredToWorld3DEN = "_this call bro_fnc_snap_mship;";
		};
		class MarkerLights {
			class bro_mship_interiorlight_1 {
				color[]={1,1,1,1};
				diffuse[]={1,1,1};
				name="interior_light_1";
				ambient[]={0.1,0.1,0.1,0};
				brightness=1;
				intensity=8000;
				drawLight=0;
				blinking=0;
				dayLight=1;
				useFlare=0;
				class Attenuation {
					start=0;
					constant=0;
					linear=0;
					quadratic=10;
				};
				position[]={0,0.2,0};
			};
		};
	};
	class Land_Bro_MSHIP_hugeroom: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Rooms: Huge";
		model = "bro_modular_ship\bro_mship_hugeroom.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hugeroom.jpg";
		class MarkerLights: MarkerLights {
			class bro_mship_Hugeroom_Light_1: bro_mship_interiorlight_1 {
				ambient[]={0.15,0.15,0.15,0};
				intensity=10000;
				class Attenuation {
					start=0;
					constant=0;
					linear=0;
					quadratic=1;
				};
			};
			class bro_mship_Hugeroom_Light_2: bro_mship_Hugeroom_Light_1 {
				name="interior_light_2";
			};
		};
	};
	class Land_Bro_MSHIP_bigroom: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Rooms: Big";
		model = "bro_modular_ship\bro_mship_bigroom.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_bigroom.jpg";
	};
	class Land_Bro_MSHIP_bigroom_through: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Rooms: Big, Thru";
		model = "bro_modular_ship\bro_mship_bigroom_through.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_bigroom_through.jpg";
	};
	class Land_Bro_MSHIP_smallroom: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Rooms: Small";
		model = "bro_modular_ship\bro_mship_smallroom.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_smallroom.jpg";
	};
	class Land_Bro_MSHIP_smallroom_through: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Rooms: Small, Thru";
		model = "bro_modular_ship\bro_mship_smallroom_through.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_smallroom_through.jpg";
	};
	class Land_Bro_MSHIP_hallway_2m: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: 2m";
		model = "bro_modular_ship\bro_mship_hallway_2m.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_2m.jpg";
	};
	class Land_Bro_MSHIP_hallway_4m: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: 4m";
		model = "bro_modular_ship\bro_mship_hallway_4m.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_4m.jpg";
	};
	class Land_Bro_MSHIP_hallway_8m: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: 8m";
		model = "bro_modular_ship\bro_mship_hallway_8m.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_8m.jpg";
	};
	class Land_Bro_MSHIP_hallway_corner: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: Corner";
		model = "bro_modular_ship\bro_mship_hallway_corner.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_corner.jpg";
	};
	class Land_Bro_MSHIP_hallway_tee: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: T";
		model = "bro_modular_ship\bro_mship_hallway_tee.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_tee.jpg";
	};
	class Land_Bro_MSHIP_hallway_cross: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: Cross";
		model = "bro_modular_ship\bro_mship_hallway_cross.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_cross.jpg";
	};
	class Land_Bro_MSHIP_hallway_stairs: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Hallway: Stairs";
		model = "bro_modular_ship\bro_mship_hallway_stairs.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_hallway_stairs.jpg";
	};
	class Land_Bro_MSHIP_Door: Land_Bro_MSHIP_Base {
		scope = 2;
		displayName = "Ship Door";
		model = "bro_modular_ship\bro_mship_door.p3d";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_Door.jpg";
		numberOfDoors = 1;
		class MarkerLights {};
		class AnimationSources {
			class Door_1 {
				source = "user";
				animPeriod = 0.8;
				initPhase = 0;
			};
			class Door_1_sound_source: Door_1 {
				Sound = "MetalDoorsSound";
				soundPosition="Door_1_trigger";
			};
			class Door_1_locked_source: Door_1{};
		};
		class UserActions {
			class OpenDoor_1 {
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2' />";
				displayName="$STR_DN_OUT_O_DOOR";
				position="Door_1_trigger";
				actionNamedSel="Door_1";
				radius=1.4;
				onlyForPlayer=1;
				condition="((this animationSourcePhase 'Door_1_sound_source') < 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 1, 1] call BIS_fnc_Door)";
			};
			class CloseDoor_1: OpenDoor_1 {
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2' />";
				displayName="$STR_DN_OUT_C_DOOR";
				condition="((this animationSourcePhase 'Door_1_sound_source') >= 0.5) && ((this getVariable ['bis_disabled_Door_1', 0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 1, 0] call BIS_fnc_Door)";
			};
		};
	};
	class Land_Bro_MSHIP_Door_Fake: Land_Bro_MSHIP_Door {
		scope = 2;
		displayName = "Ship Door (Fake)";
		numberOfDoors = 0;
		class AnimationSources {};
		class UserActions {};
	};
	class Land_Bro_MSHIP_Sign: Land_Bro_MSHIP_Base {
		scope = 2;
		icon = "a3\ui_f\data\map\vehicleicons\iconobject_2x1_ca.paa";
		displayName = "Ship Room Sign";
		editorPreview = "bro_modular_ship\thumbs\Land_Bro_MSHIP_Sign.jpg";
		model = "bro_modular_ship\bro_mship_sign.p3d";
		hiddenSelections[]={
			"camo"
		};
		hiddenSelectionsTextures[]={
			""
		};
		class MarkerLights {};
		class Attributes {
			class ObjectTextureCustom0 {
				displayName="Text";
				tooltip="Text on the sign.\nUse backslash + n for linebreak.";
				property="ObjectTextureCustom0";
				control="Edit";
				expression="[_this,_value] call bro_fnc_sign_mship;";
				defaultValue="(getObjectTextures _this) param [0,'',['']]";
			};
		};
	};
};