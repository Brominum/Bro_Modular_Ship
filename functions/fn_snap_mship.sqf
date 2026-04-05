/*
	bin_fnc_cargoPlatform_01_update
	Update cargo platform position (3D Snapping Enabled)
*/
params["_object"];

if ((is3DEN && {current3DENOperation != "" || {get3DENActionState "MoveGridToggle" == 0}})) exitWith {};

private _nearbyObjects = nearestObjects [_object, ["Land_Bro_MSHIP_Base"], 10];
_nearbyObjects = _nearbyObjects - [_object];

if (_nearbyObjects isEqualTo[]) exitWith {};

private _nearestObject = _nearbyObjects # 0;

// Dynamically find snap points (Checks snap_1 through snap_8)
private _snapPointsParent =[];
for "_i" from 1 to 8 do
{
	private _selPos = _object selectionPosition format["snap_%1",_i];
	if !(_selPos isEqualTo [0,0,0]) then {
		_snapPointsParent pushBack _selPos;
	};
};

if (_snapPointsParent isEqualTo[]) exitWith {};

private _snapped = false;

for "_i" from 1 to 8 do
{
	if (_snapped) exitWith {};

	private _targetSelPos = _nearestObject selectionPosition format["snap_%1",_i];
	if !(_targetSelPos isEqualTo [0,0,0]) then {
		private _snapPointASL = _nearestObject modelToWorldVisualWorld _targetSelPos;

		{
			private _parentModelPos = _x;
			private _parentWorldASL = _object modelToWorldVisualWorld _parentModelPos;

			// Check distance in true 3D space
			if (_snapPointASL distance _parentWorldASL <= 1.5) exitWith
			{
				// Adjust direction
				private _dirTo = getDir _nearestObject - 360;
				private _dirObject = getDir _object;
				private _dir = _dirTo;

				for "_j" from 0 to 7 do
				{
					_dir = _dirTo + _j * 90;
					if(abs(_dir - _dirObject) < 45) then
					{
						_j = 10;
					};
				};
				
				_object set3DENAttribute["rotation", [0,0, _dir]];

				// Calculate mathematical rotated offset to avoid 1-frame engine delay
				private _currentModelOriginASL = _object modelToWorldVisualWorld [0,0,0];
				
				_parentModelPos params ["_mx", "_my", "_mz"];
				private _wx = (_mx * cos _dir) + (_my * sin _dir);
				private _wy = -(_mx * sin _dir) + (_my * cos _dir);
				private _wz = _mz;
				
				private _rotatedOffset = [_wx, _wy, _wz];
				private _currentSnapPointASL = _currentModelOriginASL vectorAdd _rotatedOffset;

				// Calculate the exact 3D translation vector needed
				private _shift = _snapPointASL vectorDiff _currentSnapPointASL;

				// Apply translation to object's current ASL position
				private _currentPosASL = getPosASL _object;
				private _newPosASL = _currentPosASL vectorAdd _shift;

				// Convert to ATL so the Eden Editor accepts the exact correct height
				_object set3DENAttribute["position", ASLToATL _newPosASL];

				_snapped = true;
			};
		} forEach _snapPointsParent;
	};
};