open ReactFrp.React;
open ReactReact;
// open ReactReact.Utils;

let counter = ref(0);
let (timeS, timeF) = S.create(counter^);
let timeIncrement = () => {
  counter := counter^ + 1;
  timeF(counter^);
};
let timerId = Js.Global.setInterval(timeIncrement, 1000);
let vdomS = _ =>
  S.map(
    ~eq=(_, _) => false,
    time => {
      let timeMessage = time == 1 ? "second" : "seconds";
      let message = {j|You've spent $time $timeMessage on this page!|j};
      <div> {ReasonReact.string(message)} </div>;
    },
    timeS,
  );
[@react.component]
let make = () => componentFromSignal(vdomS, ());