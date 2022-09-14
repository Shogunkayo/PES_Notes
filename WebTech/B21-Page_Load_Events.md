# PAGE LOAD EVENTS
---
- When a page is opened, the following events occur in order
1. `DOMContenLoaded` - the browser fully loads HTML and completes building the DOM tree,  but external resources havent been loaded
2. `load` - the external resources like stylesheets are loaded

- When a page is closed, the following events occur in order
1. `beforeunload` - fires before the page and resources are unloaded, used to show a confirmation dialogue
2. `unload` - fires when the page has completely unloaded, used to send analytic data or clean up resources
