# LIFECYCLE METHODS
---
- Series of events that happen from the staring of the React component to its ending
1. Mounting - birth of the component
2. Updating - growth of the component
3. Unmounting - end of the component

### Methods
1. `constructor()`
   - premounting phase
   - `super()` is called so that the properties of `React.Component` is inherited and additional functionalities can be added
   - If `props` is not initialized in the constructor, it might lead to errors

2. `componentWillMount()`
   - called only once in the lifecycle
   - executed before rendering on both client and server side
   - useful in scenarios where the date and time has to be set depending on the client
```
componentWillMount(){
	this.setState({startDateTime: new Date(Date.now())});
}
```

3. `render()`
   - Handles rendering of the component 
   - Accesses `this.state` and `this.props`

4. ` componentDidMount()`
   - called only once, immediately after the component is rendered
   - indicates that the HTML of the component has been rendered into the DOM and can be accessed 

5. `componentWillReceiveProps()`
   - allows to match incomming props with the current props
   - invoked as soon as props are updated

6. `shouldComponentUpdate()`
   - allows a component to exit the update lifecycle

1. `componentWillUpdate()`
   - called just before rendering while updating a component
   - will not be invoked if `shouldComponentUpdate` returns false

8. `componentDidUpdate()`
   - invoked immediately after update
   - not called during initial render
   - will not be invoked if `shouldComponentUpdate` returns false

9. `componentWillUnmount()`
   - last method to be called, before the component is removed from the DOM
   - used to perform clean-up of DOM elements and timers created
```
componentWillUnmount(){
	clearInterval(this.interval);
}
```

- `ReactDOM.unmountComponentAtNode(node)` is used to delete the component from the DOM
- `componentWillUpdate()`, `componentWillMount()` has been replaced by `getSnapshotBeforeUpdate()` and `componentWillRecieveProps()` has been replaced by `getDerivedStateFromProps()`; the older versions are marked unsafe for use
