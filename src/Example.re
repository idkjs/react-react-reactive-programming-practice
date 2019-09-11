open ReactFrp.React;
open ReactReact;
open ReactReact.Utils;

module ShowTime = {
  let vdomS = propsS =>
    S.map(
      ~eq=(_, _) => false,
      time =>
        if (time != "") {
          let timeNow = {j|Hello, $time!|j};
          <p> {ReasonReact.string(timeNow)} </p>;
        } else {
          <p> {ReasonReact.string("I dont know the time!")} </p>;
        },
      propsS,
    );
  [@react.component]
  let make = (~time) => componentFromSignal(vdomS, time);
};
module InputTime = {
  let initial = Js.Date.now();
  let json_of_date = (d: float): Js.Json.t =>
    d |> Js.Date.fromFloat |> Js.Date.toISOString |> Json.Encode.string;
  let date_of_json = (json: Js.Json.t): float =>
    Json.Decode.string(json) |> Js.Date.fromString |> Js.Date.valueOf;
  Js.log2("initial", initial);
  Js.log2("json_of_date", json_of_date(initial));
  let dateJson = json_of_date(initial);
  let dateJsonToString = dateJson->Json.Decode.string;
  Js.log2("date_of_json", date_of_json(json_of_date(initial)));
  Js.log2("dateJsonToString", dateJsonToString);
  let (timeS, timeF) = S.create(dateJsonToString);
  let vdomS = _ =>
    S.map(
      ~eq=(_, _) => false,
      time => <div> <ShowTime time /> </div>,
      timeS,
    );
  [@react.component]
  let make = () => componentFromSignal(vdomS, ());
};
module ShowName = {
  let vdomS = propsS =>
    S.map(
      ~eq=(_, _) => false,
      name =>
        if (name != "") {
          let greeting = {j|Hello, $name!|j};
          <p> {ReasonReact.string(greeting)} </p>;
        } else {
          <p> {ReasonReact.string("Hello, unknown person!")} </p>;
        },
      propsS,
    );
  [@react.component]
  let make = (~name) => componentFromSignal(vdomS, name);
};


module Time = {
  let json_of_date = (d: float): Js.Json.t =>
    d |> Js.Date.fromFloat |> Js.Date.toISOString |> Json.Encode.string;
  let date_of_json = (json: Js.Json.t): float =>
    Json.Decode.string(json) |> Js.Date.fromString |> Js.Date.valueOf;

  let dateJson = json_of_date(Js.Date.now());
  let dateJsonToString = dateJson->Json.Decode.string;
  let getDate = dateJson->Json.Decode.string;
  let counter = ref(0);
  let (timeS, timeF) = S.create(counter^);
  let timeIncrement = () => {
    counter := counter^ + 1;
    Js.log2("counter", counter);
    timeF(counter^);
  };
  // let timeIncrement = () => {
  //   counter := getDate();
  //   Js.log2("counter", counter);
  //   timeF(counter^);
  // };
  Js.log2("timeIncrement", timeIncrement());
  let timerId = Js.Global.setInterval(timeIncrement, 1000);
  let vdomS = _ =>
    S.map(
      ~eq=(_, _) => false,
      time => {
        // let timeMessage = time == 1 ? "second" : "seconds";
        Js.log2("time_vdom:", time);
        let timeMessage = time == 1 ? "second" : "seconds";
        let currentTimeS = Js.Date.now()->json_of_date->Json.Decode.string;
        Js.log2("currentTime_NOW_String", currentTimeS);
        // let currentTime = getDate;
        // Js.log2("currentTime", currentTime);
        let message = {j|You've spent $time $timeMessage on this page $currentTimeS !|j};
        <div> {ReasonReact.string(message)} </div>;
      },
      timeS,
    );
  [@react.component]
  let make = () => componentFromSignal(vdomS, ());
};

module Date = {
  let json_of_date = (d: float): Js.Json.t =>
    d |> Js.Date.fromFloat |> Js.Date.toISOString |> Json.Encode.string;
  let date_of_json = (json: Js.Json.t): float =>
    Json.Decode.string(json) |> Js.Date.fromString |> Js.Date.valueOf;

  let getDate = () => Js.Date.now()->json_of_date->Json.Decode.string
  let counter = ref(0);
  let date = ref(getDate());
  Js.log2("date_ref", date);
  // let (dateS, dateF) = S.create(date^);
  let (dateS, dateF) = S.create(getDate());
  let timeIncrement = () => {
    // increment the counter which is passed to timerId
    counter := counter^ + 1;
    Js.log2("counter", counter);
    // let olddate = date^;
    let olddate = dateS;
    Js.log2("olddate", olddate);
    let newdate = getDate();
    Js.log2("newdate", newdate);
    // update the date and set it on `dateF` which is our updated variable
    // dateF(newdate);
    dateF(getDate());
  };

  let timerId = Js.Global.setInterval(timeIncrement, 1000);
  let vdomS = _ =>
    S.map(
      ~eq=(_, _) => false,
      date => {

        // let currentTime = Js.Date.now()->json_of_date->Json.Decode.string;
        let currentTime = getDate();
        Js.log2("currentTime", currentTime);
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
};

module Input = {
  let (nameS, nameF) = S.create("");
  let vdomS = _ =>
    S.map(
      ~eq=(_, _) => false,
      name =>
        <>
          <input type_="text" onChange={ev => emitEventToStream(nameF, ev)} />
          <ShowName name />
          <h1> {ReasonReact.string("Timer.re")} </h1>
          <Timer />
          <h1> {ReasonReact.string("Time.re")} </h1>
          <Time />
          <h1> {ReasonReact.string("Date.re")} </h1>
          <Date />
          <h1> {ReasonReact.string("WithButton.re")} </h1>
          <WithButton />
        </>,
      nameS,
    );
  [@react.component]
  let make = () => componentFromSignal(vdomS, ());
};

// ReactDOMRe.renderToElementWithId(<Input />, "index");