# KEYBOARD EVENTS
---
- Three main keyboard events,
1. `keydown` - fires when a key is pressed, and continues firing untill released
2. `keyup` - fired when a key is released
3. `keypress` - fires when a character like 'a' is pressed, does not work on special keys like left arrow

- both `keydown` and `keyup` are fired before any changes are made to the element

## Properties
- `key` returns the character that has been pressed
- `code` returns the physical key code

-> If the key 'z' is pressed, `key` returns 'z' and `code` returns 'KeyZ'