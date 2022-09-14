# MOUSE EVENTS
---
- DOM Level 3 defines 9 mouse events
- When an element is clicked,  the following events are fired in order
1. `mousedown` - when an element is pressed
2. `mouseup` - when the mouse button is released 
3. `click` - when one mousedown and mouseup is detected on an element

- `dblclick` event is fired when an element is `click`ed twice. The following events are fired
1. mousedown
2. mouseclick
3. click
4. mousedown
5. mouseclick
6. click
7. dblclick

- `mousemove` event is continously fired whenever the mouse passes over an element
- It will slow down the page
- It is registed only when needed and removed afterwards

- `mouseenter` is fired once when the cursor enters an element
- `mouseleave` is fired once when the cursor leaves an element
- Both of them do not bubble and do not fire when cursor is moved over descendent elements

## Mouse Buttons
- The event object passed to the mouse event handler has a property called button which indicates which mouse button was pressed
![mouse1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/WebTech/Images/mouse1.png)

## Modifier Keys
- SHIFT, CTRL, ALT, META

## Coordinates
- `screenX` and `screenY` : relative to entire screen
- `clientX` and `clientY` : relative to the window where event was fired 
