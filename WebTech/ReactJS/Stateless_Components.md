# STATELESS COMPONENTS
---
- Does not use `state` and does not have a lifecycle
- Usually contain only the `render` method
- For performance and clarity of code, such components should be written as functions instead of classes
- The `render()` method itself can be made into a component

*A functional component is always a stateless component but a class component can be either a stateful or a stateless component*

| Stateful                                                               | Stateless                                 |
| ---------------------------------------------------------------------- | ----------------------------------------- |
| Also called container, smart components                                | Also called presentation, dumb components |
| Have a state                                                           | Do not have a state                       |
| Can render both props and states: {this.props.name}, {this.state.name} | Can render only props: {props.name}       |
| Always a class component                                               | Can be a class or function component                                          |

#### Use cases for stateless:
- just to present the props
- dont need an internal variable
- create non interactive element
- want reusable code

#### Use cases for stateful:
- create an element which accepts user input
- element is interactive
- dependent on state for rendering 
- dependent on data that cannot be passed down as props

### Creation 
```
const NewComponent = (props) => (code with implicit return)
```
- This method only works for a single expression

```
function NewComponent(props){
	code with explicit return
}
```

Example showcasing the use of `props.children` in a stateless component
```
function TestComponent(props){
	return <h1> Welcome, {props.children} </h1>
}

ReactDOM.render(<TestComponent>User</TestComponent>, document.getElementById("container"));
```

### Nesting
```
function ComponentOne(props){
	var greeting = "Welcome"
	return <ComponentTwo> {greeting}, {props.text} </ComponentTwo>
}

function ComponentTwo(props){
	return <h1>{props.children}</h1>
}      

ReactDOM.render(
	<div>
		<ComponentOne text="Hello"/>
		<ComponentOne text="World"/>
	</div> , document.getElementById("container"));
```

The above code displays the output,
```
Welcome, Hello
Welcome, World
```

