# Protocolo de Comunicacion:
> Nos comunicaremos principalmente mediante archivos .json.
> Que protocolo iria mejor?

1.Ejemplo conceptual:
```json
{
  "type": "MOVE_JOINT",
  "joint": 2,
  "angle_deg": 45,
  "speed": 0.8
}
```
2. Ejemplo 2
```json
{
  "command": "move_axis",
  "axis": 2,
  "position": 45.5,
  "speed": 50,
  "timestamp": "2024-01-15T10:30:00Z"
}
```
2. Low level

```json
{
  "type": "SET_STEPPERS",
  "motors": [
    { "id": 0, "steps": 1200 },
    { "id": 1, "steps": -300 }
  ]
}
```
