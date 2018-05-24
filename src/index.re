[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <Page />
  </ReasonApollo.Provider>,
  "root",
);

register_service_worker();