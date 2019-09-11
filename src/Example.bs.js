// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReactReact = require("@denommus/react-react/src/reactReact.bs.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var React$ReactFrp = require("react-frp/src/react.js");
var Timer$ReactHooksTemplate = require("./Timer.bs.js");
var WithButton$ReactHooksTemplate = require("./WithButton.bs.js");

function vdomS(propsS) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (time) {
                if (time !== "") {
                  var timeNow = "Hello, " + (String(time) + "!");
                  return React.createElement("p", undefined, timeNow);
                } else {
                  return React.createElement("p", undefined, "I dont know the time!");
                }
              }), propsS);
}

function Example$ShowTime(Props) {
  var time = Props.time;
  return ReactReact.componentFromSignal(vdomS, time);
}

var ShowTime = /* module */[
  /* vdomS */vdomS,
  /* make */Example$ShowTime
];

var initial = Date.now();

function json_of_date(d) {
  return new Date(d).toISOString();
}

function date_of_json(json) {
  return new Date(Json_decode.string(json)).valueOf();
}

console.log("initial", initial);

console.log("json_of_date", new Date(initial).toISOString());

var dateJson = new Date(initial).toISOString();

var dateJsonToString = Json_decode.string(dateJson);

var json = new Date(initial).toISOString();

console.log("date_of_json", new Date(Json_decode.string(json)).valueOf());

console.log("dateJsonToString", dateJsonToString);

var match = React$ReactFrp.S[/* create */1](undefined, dateJsonToString);

var timeS = match[0];

function vdomS$1(param) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (time) {
                return React.createElement("div", undefined, React.createElement(Example$ShowTime, {
                                time: time
                              }));
              }), timeS);
}

function Example$InputTime(Props) {
  return ReactReact.componentFromSignal(vdomS$1, /* () */0);
}

var InputTime_006 = /* timeF */match[1];

var InputTime = /* module */[
  /* initial */initial,
  /* json_of_date */json_of_date,
  /* date_of_json */date_of_json,
  /* dateJson */dateJson,
  /* dateJsonToString */dateJsonToString,
  /* timeS */timeS,
  InputTime_006,
  /* vdomS */vdomS$1,
  /* make */Example$InputTime
];

function vdomS$2(propsS) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (name) {
                if (name !== "") {
                  var greeting = "Hello, " + (String(name) + "!");
                  return React.createElement("p", undefined, greeting);
                } else {
                  return React.createElement("p", undefined, "Hello, unknown person!");
                }
              }), propsS);
}

function Example$ShowName(Props) {
  var name = Props.name;
  return ReactReact.componentFromSignal(vdomS$2, name);
}

var ShowName = /* module */[
  /* vdomS */vdomS$2,
  /* make */Example$ShowName
];

function json_of_date$1(d) {
  return new Date(d).toISOString();
}

function date_of_json$1(json) {
  return new Date(Json_decode.string(json)).valueOf();
}

var d = Date.now();

var dateJson$1 = new Date(d).toISOString();

var dateJsonToString$1 = Json_decode.string(dateJson$1);

var getDate = Json_decode.string(dateJson$1);

var counter = /* record */[/* contents */0];

var match$1 = React$ReactFrp.S[/* create */1](undefined, counter[0]);

var timeF = match$1[1];

var timeS$1 = match$1[0];

function timeIncrement(param) {
  counter[0] = counter[0] + 1 | 0;
  console.log("counter", counter);
  return Curry._2(timeF, undefined, counter[0]);
}

console.log("timeIncrement", timeIncrement(/* () */0));

var timerId = setInterval(timeIncrement, 1000);

function vdomS$3(param) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (time) {
                console.log("time_vdom:", time);
                var match = time === 1;
                var timeMessage = match ? "second" : "seconds";
                var d = Date.now();
                var currentTimeS = Json_decode.string(new Date(d).toISOString());
                console.log("currentTime_NOW_String", currentTimeS);
                var message = "You\'ve spent " + (String(time) + (" " + (String(timeMessage) + (" on this page " + (String(currentTimeS) + " !")))));
                return React.createElement("div", undefined, message);
              }), timeS$1);
}

function Example$Time(Props) {
  return ReactReact.componentFromSignal(vdomS$3, /* () */0);
}

var Time = /* module */[
  /* json_of_date */json_of_date$1,
  /* date_of_json */date_of_json$1,
  /* dateJson */dateJson$1,
  /* dateJsonToString */dateJsonToString$1,
  /* getDate */getDate,
  /* counter */counter,
  /* timeS */timeS$1,
  /* timeF */timeF,
  /* timeIncrement */timeIncrement,
  /* timerId */timerId,
  /* vdomS */vdomS$3,
  /* make */Example$Time
];

function json_of_date$2(d) {
  return new Date(d).toISOString();
}

function date_of_json$2(json) {
  return new Date(Json_decode.string(json)).valueOf();
}

function getDate$1(param) {
  var d = Date.now();
  return Json_decode.string(new Date(d).toISOString());
}

var counter$1 = /* record */[/* contents */0];

var d$1 = Date.now();

var date = /* record */[/* contents */Json_decode.string(new Date(d$1).toISOString())];

console.log("date_ref", date);

var d$2 = Date.now();

var match$2 = React$ReactFrp.S[/* create */1](undefined, Json_decode.string(new Date(d$2).toISOString()));

var dateF = match$2[1];

var dateS = match$2[0];

function timeIncrement$1(param) {
  counter$1[0] = counter$1[0] + 1 | 0;
  console.log("counter", counter$1);
  console.log("olddate", dateS);
  var d = Date.now();
  var newdate = Json_decode.string(new Date(d).toISOString());
  console.log("newdate", newdate);
  var d$1 = Date.now();
  return Curry._2(dateF, undefined, Json_decode.string(new Date(d$1).toISOString()));
}

var timerId$1 = setInterval(timeIncrement$1, 1000);

function vdomS$4(param) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (date) {
                var d = Date.now();
                var currentTime = Json_decode.string(new Date(d).toISOString());
                console.log("currentTime", currentTime);
                var message = "Today\'s date is " + (String(date) + " !");
                var currentTimeMessage = "Today\'s date is " + (String(currentTime) + " !");
                return React.createElement(React.Fragment, undefined, React.createElement("div", undefined, message), React.createElement("div", undefined, currentTimeMessage));
              }), dateS);
}

function Example$Date(Props) {
  return ReactReact.componentFromSignal(vdomS$4, /* () */0);
}

var $$Date$1 = /* module */[
  /* json_of_date */json_of_date$2,
  /* date_of_json */date_of_json$2,
  /* getDate */getDate$1,
  /* counter */counter$1,
  /* date */date,
  /* dateS */dateS,
  /* dateF */dateF,
  /* timeIncrement */timeIncrement$1,
  /* timerId */timerId$1,
  /* vdomS */vdomS$4,
  /* make */Example$Date
];

var match$3 = React$ReactFrp.S[/* create */1](undefined, "");

var nameF = match$3[1];

var nameS = match$3[0];

function vdomS$5(param) {
  return React$ReactFrp.S[/* map */10]((function (param, param$1) {
                return false;
              }), (function (name) {
                return React.createElement(React.Fragment, undefined, React.createElement("input", {
                                type: "text",
                                onChange: (function (ev) {
                                    return ReactReact.Utils[/* emitEventToStream */0]((function (eta) {
                                                  return Curry._2(nameF, undefined, eta);
                                                }), ev);
                                  })
                              }), React.createElement(Example$ShowName, {
                                name: name
                              }), React.createElement("h1", undefined, "Timer.re"), React.createElement(Timer$ReactHooksTemplate.make, { }), React.createElement("h1", undefined, "Time.re"), React.createElement(Example$Time, { }), React.createElement("h1", undefined, "Date.re"), React.createElement(Example$Date, { }), React.createElement("h1", undefined, "WithButton.re"), React.createElement(WithButton$ReactHooksTemplate.make, { }));
              }), nameS);
}

function Example$Input(Props) {
  return ReactReact.componentFromSignal(vdomS$5, /* () */0);
}

var Input = /* module */[
  /* nameS */nameS,
  /* nameF */nameF,
  /* vdomS */vdomS$5,
  /* make */Example$Input
];

exports.ShowTime = ShowTime;
exports.InputTime = InputTime;
exports.ShowName = ShowName;
exports.Time = Time;
exports.$$Date = $$Date$1;
exports.Input = Input;
/* initial Not a pure module */