const callback = require('./build/Release/callback');

var callme = function() {
    console.log("I've been called!");
}

callback.callthis(callme);