open ReactFrp.React;
open ReactReact;

let json_of_date = (d: float): Js.Json.t =>
  d |> Js.Date.fromFloat |> Js.Date.toISOString |> Json.Encode.string;
let date_of_json = (json: Js.Json.t): float =>
  Json.Decode.string(json) |> Js.Date.fromString |> Js.Date.valueOf;

let getDate = () => Js.Date.now()->json_of_date->Json.Decode.string;
let counter = ref(0);
let date = ref(getDate());
Js.log2("date_ref", date);
let (dateS, dateF) = S.create(date^);

let timeIncrement = () => {
  /*   Here we are completing two tasks, updating the counter ref and updating the date ref
   */
  // increment the counter which is passed to timerId
  counter := counter^ + 1;
  /*   update the date by referencing our date ref variable which calls `Js.Date.now` to get the current time and set it on `dateF` which is our updated variable then store the value returned from `getDate()` in reference date. */

  // Js.log2("set date ref", date^);
  date := getDate();
  // Js.log2("set date ref after", date^);
  /*   set pass the value from the date reference, here updated with `getDate()` to `dateF`, our update function. */
  dateF(date^);
};

let timerId = Js.Global.setInterval(timeIncrement, 1000);
let vdomS = _ =>
  S.map(
    ~eq=(_, _) => false,
    date => {
      // let currentTime = Js.Date.now()->json_of_date->Json.Decode.string;
      let currentTime = getDate();
      // Js.log2("currentTime", currentTime);
      // let currentTime = getDate;
      // Js.log2("currentTime", currentTime);
      // pass the incoming date as variable
      let message = {j|Today's date is $date !|j};
      // or generate the incoming date here in `vdomS` and pass it.
      let currentTimeMessage = {j|Today's date is $currentTime !|j};
      <>
        <div> {ReasonReact.string(message)} </div>
        <div> {ReasonReact.string(currentTimeMessage)} </div>
      </>;
    },
    dateS,
  );
[@react.component]
let make = () => componentFromSignal(vdomS, ());