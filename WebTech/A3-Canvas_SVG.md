# CANVAS
----
- Canvas API provides a means for drawing graphics via JavaScript and HTML `<canvas>` element
- Canvas allows rendering graphics powered by JavaScript
- `<canvas>` is only the container for the graphics. All drawing must be done inside JavaScript using the context object

| Method                                  | Function                                                                                                                      |
| --------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| fillRect(x,y,width,height)              | Draws a filled rectangle                                                                                                      |
| strokeRect(x,y,width,height)            | Draws a rectangle outline                                                                                                     |
| clearRect(x,y,width,height)             | Clears a rectangle area, making it transparent                                                                                |
| moveTo(x,y)                             | Moves the pen to the coordinates specified by x and y                                                                         |
| lineTo(x,y)                             | Draws a line from the current drawing position to x and y                                                                     |
| arc(x,y,r,sAngle,eAngle,anticlockwise)  | Draws an arc starting at x,y with radius r starting with sAngle and ending with eAngle going anticlockwise(default clockwise) |
| arcTo(x1,y1,x2,y2,r)                    | Draws an arc                                                                                                                  |
| createLinearGradient(x1,y1,x2,y2)       | Creates a linear gradient                                                                                                     |
| createRadialGradient(x1,y1,r1,x2,y2,r2) | Creates a radial gradient                                                                                                     |
| fillText(text,x,y,maxWidth])            | Fills the text at given position                                                                                              |
| strokeText(text,x,y,maxWidth)           | Draws outline of given text                                                                                                   |
| drawImage(image, x, y, width, height)                                        |                                                                                                                               |


# SVG
----
- stands for Scalable Vector Graphics
- defines vector based graphics in XML format
```
<svg width="100" height="100">
</svg>
```
- graphics are included between the `<svg>` tags


-> Drawing a circle
```
<circle cx="50" cy="30" r="50" fill="lime" stroke="green" stroke-width="2" />
```
- cx and cy are the coordinates of the centre of the circle, 0 by default
- r is the radius

-> Drawing a rectangle
```
<rect width="100" height="50" style="fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)"/>
```

-> Drawing an ellipse
```
<ellipse cx="100" cy="70" rx="85" ry="55" fill="blue">
```
- rx is the horizontal radius and ry is the vertical radius

-> Dragwing a line
```
 <line x1="0" y1="0" x2="200" y2="200" style="stroke:rgb(255,0,0);stroke-width:2" />
```

-> Drawing a polygon (any shape with atleast 3 sides)
```
<polygon points = "200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:3">
```

-> Drawing a polyline (any shape consisting of lines)
```
<polyline points="20,20 40,25 60,40 80,120 120,140 200,180"
  style="fill:none;stroke:black;stroke-width:3" />
```