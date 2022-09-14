# JQUERY
----
- A lightweight, "write less, do more" and open source JavaScript library that simplifies programming 
- Purpose is to make JavaScript easier to use
- Released in Jan 2006 at BarCampNYC by John Resig

- HTML elements are "queried" and actions are performed on them 
- Basic syntax,
```
$(selector).action()
```

- Example, to hide all the elements with id "test"
```
$("#test").hide()
```
- To do the above task in JavaScript,
```
document.getElementByID("test").style.display="none";
```


## Document Ready Event
- All JQuery code are written inside this event to prevent running before the document has fully loaded
```
$(document).ready(function(){
	// code
});
```

