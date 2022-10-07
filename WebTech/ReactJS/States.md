# States
----
- The `state` object is where property values belonging to an object are stored
- When `state` object changes, the component is re-rendered
- It can only be accessed and modified within the component 
- A component should have an intial state

| State                                                                        | Props                       |
| ---------------------------------------------------------------------------- | --------------------------- |
| Mutable                                                                      | Immutable                   |
| Can be used in class components and function components by using React Hooks | No limitations              |
| Generally updated by event handlers                                          | Set by the parent component | 

```
class MyComponent extends React.Component{
	constructor(props){
		super(props);
		this.state = {attribute1 : 'value1', attributeN: 'valueN'};
	}
}
```
- The attributes are accessed inside the component like,
```
this.state.attribute1
```

```
class Car extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      brand: "Ford",
      model: "Mustang",
      color: "red",
      year: 1964
    };
  }
  render() {
    return (
      <div>
        <h1>My {this.state.brand}</h1>
        <p>
          It is a {this.state.color}
          {this.state.model}
          from {this.state.year}.
        </p>
      </div>
    );
  }
}
```

- The state must always be updated using `setState()` method
```
changeColor(){
    this.setState({color: "blue"});
  }
```

Example:- Constructing a Digital Clock in React
```
class DigitalClock extends React.Component{
	constructor(props){
		super(props);
		this.state var buttonColor = {
                   
               }= {time: new Date()}
	}

	tick = () => {
		this.setState({time: new Date()});
	}

	render(){
		setInterval(this.tick, 1000)
		return(<h1>{this.state.time.toLocaleTimeString()}</h1>)
	}
}
```
- `this.state.time.toLocaleTimeString()` is a built-in method which returns the time of the local environment as a string

Example:- To update an element on the press of a button
```
class ColorChanger extends React.Component{
   constructor(props){
		super(props);
		this.state = {name: "yellow", id:"1"}
   }

   click = () => {
	   this.setState({name: "green", id:"2"})
   }
   
   render(){
	   var buttonColor = {
			fontSize: "40px",
			backgroundColor: this.state.name
	   }
	   return(
		   <div>
				<h1 style={buttonColor}>{this.state.name}</h1>
				<button onClick={this.click}>Click Me!</button>
			</div>
	   )
   }
}
```