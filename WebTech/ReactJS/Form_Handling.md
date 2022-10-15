# FORM HANDLING
----
1. Uncontrolled Components
   - traditional HTML form inputs which remember what you have typed 
   - refs are used to get form values 
   - `defaultValue` is used to specify initial value in React
2. Controlled Components
   - render a form and control what happens in the form 
   - `state` is used to handle input value and `setState` is used to change the input value

Example for uncontrolled component
```
class UncontrolledComponent extends React.Component{
	constructor(props){
		super(props);
		this.handleSubmit = this.handleSubmit.bind(this);
		this.input = React.createRef();
	}

	handleSubmit(event){
		event.preventDefault();
		alert("Submitted"+this.input.current.value);
	}

	render(){
		return(
			<form onSubmit={this.handleSubmit}>
				Name:<input className="input" type="text" ref={this.input} />
				<input type="submit" value="Submit" />    
			</form>
		);
	}
}
```

Example for controlled component
```
class ControlledComponent extends React.Component{
	constructor(props){
		super(props);
		this.state = {value: ''};
	}

	handleChange = (event) => {
		this.setState({value:event.target.value});
	}

	handleSubmit = (event) => {
		event.preventDefault();
		alert("Submitted"+this.state.value);
	}

	render(){
		return(
			<form onSubmit={this.handleSubmit}>
				Name:<input className="input" type="text" value={this.state.value} onChange={this.handleChange} />
				<input type="submit" value="Submit" />    
			</form>
		);
	}
}
```

To handle mulitple inputs, `this.state.form` is used
```
class MultipleInputs extends React.Component{
	constructor(props){
		super(props);
		this.state = {form: {name: '', email: ''}}
	}

	render(){
		return(
			<form onSubmit={this.handleSubmit}>
			Name: <input type="text" name="email" onChange={this.handleChange} />
			Email: <input type="text" name="email" onChange={this.handleChange} />
			<input type="submit" value="Submit" /> 
			</form>
		)
	}

	handleChange = (event) => {
		var input_name = event.target.name;
		var input_email = event.target.email;
		this.setState({
			...this.state.form, 
			form:{
				...this.state.form,
				[input_name]:[input_email]
			}
		})
	}

	handleSubmit = (event) => {
		event.preventDefault();
		alert("Submitted"+this.state.form.name+this.state.form.email);
                }
            }
```