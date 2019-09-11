open ReactFrp.React;
open ReactReact;

module ShowName = {
  let vdomS = propsS =>
    S.map(
      ~eq=(_, _) => false,
      name => {
        Js.log2("show_name_ref", name);

        let greeting = {j|The new name is $name!|j};
        <p> {ReasonReact.string(greeting)} </p>;
      },
      propsS,
    );
  [@react.component]
  let make = (~name) => componentFromSignal(vdomS, name);
};

let getNewName = () => BsFaker.Lorem.words(~wordCount=3, ());
let name = ref(getNewName());
Js.log2("name_ref", name);
let (nameS, nameF) = S.create(name^);
// This is the funcion we are using to update when the click event occurs in `vdomS`
let updateOnClick = () => {
  // Generate a new name and set the name reference to it.
  // Js.log2("updateOnClick_before", name^);
  name := getNewName();
  // Js.log2("updateOnClick_after", name^);
  // Pass the updated `name` value to `nameF` which will pass it to `vdomS` instance
  nameF(name^);
  // Js.log2("updateOnClick_after_nameF", name^);
};
let vdomS = _ =>
  S.map(
    ~eq=(_, _) => false,
    name =>
      <div>
        <ShowName name />
        <button onClick={_ev => updateOnClick()}>
          "Click for new Name"->React.string
        </button>
      </div>,
    nameS,
  );
[@react.component]
let make = () => componentFromSignal(vdomS, ());