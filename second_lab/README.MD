# Завод по изготовлению автомобильных деталей

**GeneratorId** 1 3 → <br>
**SideMirror** 3 1 → Color, BasicParams <br>
**BackDoor** 2 1 → <br>
**FrontDoor** 4 4 → SideMirror <br>
**GasTank** 4 2 → Volume, Fuel <br>
**Mirror** 5 5 → <br>
**RadiatorGrille** 8 5 → BasicParams, Color <br>
**CarPart** 0 1 → <br>
**ElectroPart** 5 1 →<br>
**Starter** 7 2 → <br>
**Battery** 6 2 → <br>
**Engine** 25 19→ Rim, Prong, IntakeManifold, Piston, ValveSpring, Tube, WaterPump <br>
**Figure** 0 2 → <br>
**Triangle** 3 3 → <br>
**Circle** 1 2 → <br>
**Detail** 2 2 → <br>
**Prong** 5 2 → <br>
**Rim** 3 2 → <br>
**IntakeManifold** 4 2 → Volume, Volume, Tube <br>
**Plata** 2 0 → BasicParams <br>
**MetalCylinder** 10 0 → BaseCircle, Color <br>
**MetalLink** 2 0 → Plata, MetalCylinder <br>
**MetalChain** 1 4 → MetalLink <br>
**Piston** 15 8 → <br>
**Tube** 9 5 → BaseCircle, Color <br>
**ValveSpring** 4 4 → <br>
**WaterPump** 11 9 → <br>
**Feeler** 2 3 → <br>
**Fuel** 2 1 → Season <br>
**BasicParams** 2 0 → <br>
**Color** 1 1 → <br>
**Volume** 1 0 → <br>
**CarSetter** 0 2 → <br>
**CarStringFormatter** 0 1 → <br>
**CarLogger** 0 2 → <br>
**CarValidator** 0 1 → <br>
**MathOperations** 0 2 → <br>
**Handbrake** 2 2 → BasicParams <br>
**Season** 1 1 → <br>
**DefaultSpeedometer** 2 3 → <br>
**SpeedometerInKilometers** 2 3 → <br>
**SpeedometerInMiles** 2 3 → <br>
**BaseCircle** 1 0 → <br>
**BrakeShoe** 4 2 → Color <br>
**Wheel** 3 1 → BaseCircle, BrakeShoe <br>
**SignalButton** 2 1 → BasicParams <br>
**SteeringWheel** 3 2 → BaseCircle, BaseCircle, SignalButton <br>
**WareHouse** 2 5 → GeneratorId, CarPart <br>

## Exceptions (13)

**Exception** 1 1 → <br>
**ExceptionIncorrectRadius** 0 0 → <br>
**ExceptionIncorrectColor** 0 0 → <br>
**ExceptionIncorrectMaterial** 0 0 → <br>
**ExceptionIncorrectSize** 0 0 → <br>
**ExceptionIncorrectSerialNumber** 0 0 → <br>
**ExceptionIncorrectSeason** 0 0 → <br>
**ExceptionIncorrectFuel** 0 0 → <br>
**ExceptionIncorrectProcent** 0 0 → <br>
**ExceptionIncorrectVolume** 0 0 → <br>
**ExceptionIncorrectLevelOil** 0 0 → <br>
**ExceptionRuntimeError** 0 0 → <br>
**ExceptionWayError** 0 0 → <br>

## Итог:

**Примеры ассоциации в качестве поля класса:** 36 <br>
**Примеры ассоциации в качестве параметра функций:** 26
<p></p>

**Поля:** 175
<p></p>

**Поведения:** 127
<p></p>

**Ассоциации:** 62
<p></p>

**Исключения:** 13
<p></p>

**Всего классов:** 61