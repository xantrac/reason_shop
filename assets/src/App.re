let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    <div>
      <Component1 message="HELLO" />
      <Component2 greeting="HELLO" />
    </div>;
  },
};
