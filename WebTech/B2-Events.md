# EVENTS
---
- An action that occurs in the web browser, to which there is some response
- Each event can have a handler which executes a block of code
- `addEventListener()` is used to register an event handler
```
let btn = document.getElementById("button");
function display(){
    alert("BUTTON CLICKED");
}
btn.addEventListener('click',display);
```

- An anonymous function can also be used
```
btn.addEventListener('click', function(){
    alert("BUTTON CLICKED");
})
```

![[events.png]]


## Event Objects
- Used to obtain more information when an event occurs
- - The event object is accessible only inside the event handler
- Once all the event handlers have been executed, the event object is automatically destroyed
- When an event happens, the browser creates an event object, puts details into it and passes it as an arguement to the handler
```
btn.onclick = function(event){
                alert(event.type + " " + event.currentTarget);
                alert(event.clientX +" "+event.clientY);
            };
```

| Property/Method   | Description                                                               |
| ----------------- | ------------------------------------------------------------------------- |
| bubbles           | true if the event bubbles                                                 |
| cancelable        | true if the default behaviour of the event can be cancelled               |
| currentTarget     | the current element of which the event is firing                          |
| defaultPrevented  | return true if the event preventDefault() has been called                 |
| detail            | more information about the event                                          |
| eventPhase        | 1 for capturing phase, 2 for target and 3 for bubbling                    |
| preventDefault()  | cancel the default behaviour of element, works only if cancelable is true |
| stopPropogation() | cancel any further event bubbling, works only if bubbles is true          |
| target            | the target element of the event                                           |
| type              | the type of event that was fired                                                                          |

- The most deeply nested element which caused the event is called the target element, which can be accessed by `event.taget`

>**Event bubbling** is a method of event propagation in the HTML DOM API when an event is in an element inside another element, and both elements have registered a handle to that event. It is a process that starts with the element that triggered the event and then bubbles up to the containing elements in the hierarchy. In event bubbling, the event is first captured and handled by the innermost element and then propagated to outer elements.

The following code
![[events1.png]] 
gives the output as
![[events2.png]]

-> An example of `preventDefault()`
```
let link = document.querySelector('a');
link.addEventListener('click', function(event){
	console.log('clicked');
	event.preventDefault();
})
```

-> An example of `stopPropogation()`, without which the second code block would have executed when the first code block executes
```
let b = document.querySelector("#button");
b.addEventListener('click', function(event){
	event.stopPropogation();
	console.log("Clicked");
})

document.addEventListener('click',function(){
	console.log("Twice");
})
```
- Only "Clicked" is printed in the console


## Assigning Event Handlers

### 1. HTML Event Handler Attributes
- Event handlers typically have names that begin with "on" , for example `onclick`
- A HTML attribute with name of the event handler is used
```
<input type="button" value="CLICKED" onclick="alert("BUTTON CLICKED")">
```
- The code in the event handler can access the event object without explicitly defining it
- `this` value inside the event handler is equivalent to the event target's element
- The event handler can access the properties of the element
```
<input type="button" value="CLICKED" onclick="alert(value)">
```

##### Disadvantages
1. The event handler is mixed with HTML code, reducing readability
2. If the element is loaded before the JavaScript code, it causes timing issues and results in errors

### 2. DOM Level 0 Event Handlers
- Each element has certain event handler properties like `onclick`
- To assign an event handler, set the property to a function
```
let btn = document.getElementByID("button");
btn.onclick = function(){
	console.log("Button CLICKED");
};
```
- The anonymous function becomes a method of the element
- To remove the event handler, set the value of property to NULL
```
btn.onclick = NULL
```
- Widely used due to simplicity and cross-browser support

### 3. DOM Level 2 Event Handlers
- Two methods `addEventListener()` and `removeEventListener()` are used
- `addEventListener()` method takes 3 arguements- an event name, an event handler function  and a Boolean value that instructs the method to call the event handler during capture phase if true, else during the bubble phase
- This makes it possible to add multiple event handlers to the same element
- `removeEventListener()` removes the event handlers added via `addEventListener()`
- While adding an existing function as the event handler function, paranthesis should not be included. Else it indicates a function call, and sets the return value of the function as the event handler function


## Event Delegation
- Having a large number of event handlers will directly impact performance as
1. Each event handler is a function which inturn is an object and takes up memory
2. It takes time to assign all the event handlers which causes delay in interactivity
- Event delegation refers to the technique of levering event bubbles to handle events at a higher level in the DOM than the element on which the event originated
```
let menu = document.getElementByID("menu");
menu.addEventListener('click',(event)=>{
	let target = event.target;
	switch(target.id){
		case 'option1':
			console.log("OPTION 1");
			break;
		case 'option2':
			console.log("OPTION 2");
			break;
	}
})
```

### Advantages
- Less memory usage, better performance
- Less time required to set up event handlers on the page
- The document object is available immediately

### Limitations
- Event must be bubbling
- May add CPU load as the container handler reacts everytime an element inside it causes an event


## Custom Events
- To create a custom event,
```
let event = new CustomEvent(eventType, options);
```
- `eventType` is a string that represents the name of the event
- `options` is an object that has the `detail` property that contains any custom information about the event
```
let event = new CustomEvent('highlight', {detail:{backgroundColor:'yellow'}});
```

- After creating a custom event, it needs to be attached to an element and triggered
```
element.dispatchEvent(event);
```

## Types of Events
1. Page load events: [[B21-Page_Load_Events]]
2. Mouse events:[[B22-Mouse_Events]]
3. Keyboard events:[[B23-Keyboard_Events]]
4. Focus events:[[B24-Focus_Events]]


# EVENT PROPOGATION
---
- Two main event models - event bubbling and event capturing
- Event bubbling starts at the most specific element and propogates upwards through the parent nodes
- Event capturing starts at the least specific element and propogates downwards into the target node

## DOM 2 Level Event Model
![[events3.png]]