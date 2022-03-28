This code aim to provide a dummy screen for the argos project.
drawing to the screen will be replaced by tcp communication with an external server.

# Protocol
## clear
clear the screen
```json
{
    "type": "clear"
}
```

## draw a line
draw a line from (x0, y0) to (x1, y1)
```json
{
    "type": "draw_line",
    "x0": 0,
    "y0": 0,
    "x1": 0,
    "y1": 0
}
```

## draw a rectangle
draw a rectangle from (x, y) with width and height
```json
{
    "type": "fillRect",
    "x": 0,
    "y": 0,
    "width": 0,
    "height": 0
}
```
## set the color
set the color of the stroke color in rgb.
```json
{
    "type": "set_color",
    "r" : 0,
    "g" : 0,
    "b" : 0
}

