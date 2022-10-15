# EVENT HANDLING
---
- Event make the web app interactive and responsive to the user

| JSX                                                     | DOM                       |
| ------------------------------------------------------- | ------------------------- |
| pass function as an event handler                       | pass function as a string |
| event name is camelCase                                 | event name is lowercase   |
| have to use preventDefault to prevent default behaviour | function can return false to prevent default behaviour                    |

- List of React events
![[react_events.png]]

- As class methods are not bound by default, its necessary to bind functions to the class instance to prevent `this` from returning `undefined`
- Event handling system is called as Synthetic Event
- Event handlers are registered at the time of rendering

Example program to create a counter
```
class Counter extends React.Component{
	constructor(props){
		super(props);
		this.state = {count:0}
	}

	render(){
		return(
			<div>
				<h1>{this.state.count}</h1>
				<button onClick={this.increment}>+</button>
			</div>
		)
	}

	increment = () =>{
		this.setState((prevState) => ({count: prevState.count + 1}))
	}
}

ReactDOM.render(<Counter />, document.getElementById("container"));
```