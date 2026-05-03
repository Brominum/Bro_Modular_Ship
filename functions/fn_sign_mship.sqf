params ["_nameplate","_value"];
private _nameplateText = format ["#(rgb,1024,256,3)text(1,1,""RobotoCondensed"",0.3,""#ffffff00"",""#ffffff"",""%1"")",_value];
_nameplate setObjectTextureGlobal [0,_nameplateText];