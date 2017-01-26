/*
 * Author: ACRE2Team
 * Copies an array or an ACRE 2 hash entry inside an ACRE 2 hash
 *
 * Arguments:
 * 0: ACRE 2 Hash to be copied <HASH>/<ARRAY>
 *
 * Return Value:
 * Extracted array of values to be copied <ARRAY>
 *
 * Example:
 * [["foo1", "foo2"]] call acre_sys_core_fnc_fastHashCopyArray
 * [acreHash] call acre_sys_core_fnc_fastHashCopyArray
 *
 * Public: No
 */
#include "script_component.hpp"

private _newArray = [];
{
    if (IS_HASH(_x)) then {
        _newArray pushBack (_x call FUNC(fastHashCopy));
    } else {
        if (IS_ARRAY(_x)) then {
            _newArray pushBack (_x call FUNC(fastHashCopyArray));
        } else {
            _newArray pushBack _x;
        };
    };
} forEach _this;
_newArray;
