# WEB WORKERS
---
- Thread which executes a JavaScript file 
- Makes it possible to execute JavaScript files asynchronously and autonomously 
- Helps achieve multi threading and improving performance
- Web worker works in the background, independent of other scripts

- Web workers are created and executed in the main file, while their implementations are in a seperate JavaScript file
- In the main file,
```
var new_work = new Worker("url to the code file")
```

- The parent code may also have a callback function that listens for a response from the worker
In the main file
```
let worker = new Worker("webwork.js");
worker.postMessage("Hello");

worker.addEventListener('message', (e)=>{
	console.log("Worker said: ", e.data);
}, false);
```
In "webwork.js"
```
self.addEventListener('message', (e)=>{
    self.postMessage(e.data);
}, false);
```

- Web workers do not have access to the DOM tree of the main file

## Applications
- Listen for messages using the `onmessage` event listener function
- Send messages via `postMessage()` method
- Send AJAX requests using the XMLHttpRequest
- Create timers using `setTimeout()` and `sendInterval()` methods

## Types
1. Dedicated Worker
	- Instantiated by the main process 
	- Only accessible by the script that called it

2. Shared Worker
   - Can be reached by all processes running on the same origin
   - Can be accessed by multiple scripts




