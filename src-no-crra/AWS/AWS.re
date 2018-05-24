module AppSyncConfig = {
  type config = {
    .
    "graphqlEndpoint": string,
    "region": string,
    "authenticationType": string,
    "apiKey": string,
  };
  let config = {
    "graphqlEndpoint": "https://h25cvu6lonfilcrryg7xo5fjne.appsync-api.eu-west-1.amazonaws.com/graphql",
    "region": "eu-west-1",
    "authenticationType": "API_KEY",
    "apiKey": "da2-wj6ugvlymbhyzayd3t6ri3gcwi",
  };
};

module AppSync = {
  [@bs.module "aws-appsync"] [@bs.new]
  external makeAWSAppSyncClient :
    {
      .
      "url": Js.Nullable.t(string),
      "region": Js.Nullable.t(string),
      "auth":
        Js.Nullable.t(
          {
            .
            "type": string,
            "apiKey": string,
          },
        ),
    } =>
    'a =
    "AWSAppSyncClient";
  let createAWSAppSyncClient = (~url=?, ~region=?, ~auth=?, ()) => {
    let appSyncClientOptions = {
      "url": Js.Nullable.fromOption(url),
      "region": Js.Nullable.fromOption(region),
      "auth": Js.Nullable.fromOption(auth),
    };
    makeAWSAppSyncClient(appSyncClientOptions);
  };
};
/* module AppSync = {
     [@bs.deriving abstract]
     type authT = {
       type_: option(string),
       apiKey: option(string),
     };
     [@bs.deriving abstract]
     type appSyncClientOptionsT = {
       url: option(string),
       region: option(string),
       auth: option(authT),
     };
     [@bs.module "aws-appsync"] [@bs.new]
     external makeAWSAppSyncClient : appSyncClientOptionsT => 'a =
       "AWSAppSyncClient";
     let createAWSAppSyncClient = (~url=?, ~region=?, ~auth=?, ()) => {
       let appSyncClientOptions = appSyncClientOptionsT(~url, ~region, ~auth);
       makeAWSAppSyncClient(appSyncClientOptions);
     };
   }; */
/* let createAWSAppSyncClient = (~url=?, ~region=?, ~auth=?, ()) => {
     let appSyncClientOptions = {
       "url": Js.Nullable.fromOption(url),
       "region": Js.Nullable.fromOption(region),
       "auth": Js.Nullable.fromOption(auth),
     };
     makeAWSAppSyncClient(appSyncClientOptions);
   }; */
/* module AppSync = {
     type aWSAppSyncClientParam;
     type aWSAppSyncClient;
     [@bs.obj]
     external makeAWSAppSyncClientParam :
       (
         ~url: string,
         ~region: string,
         ~auth: {
                  .
                  "type_": string,
                  "apiKey": string,
                },
         unit
       ) =>
       aWSAppSyncClientParam =
       "";
     [@bs.module "aws-appsync"] [@bs.new]
     external aWSAppSyncClient : aWSAppSyncClientParam => aWSAppSyncClient =
       "default";
   }; */
/*
 const client = AWSAppSyncClient({
   url: graphqlEndpoint,
   region: region,
   auth: {
     type: authenticationType,
     apiKey: apiKey
   }
 });

 module AppSync = {
      [@bs.module "aws-appsync"] [@bs.scope "client"]
      external configure : 'a => unit = "";
      let configure =
          (
            ~graphqlEndpoint: string,
            ~region: string,
            ~authenticationType: string,
            ~apiKey: string,
          ) =>
        configure({
          "url": graphqlEndpoint,
          "region": region,
          "authenticationType": authenticationType,
          "apiKey": apiKey,
        });
    }; */
/*

      "graphqlEndpoint": "https://h25cvu6lonfilcrryg7xo5fjne.appsync-api.eu-west-1.amazonaws.com/graphql",
      "region": "eu-west-1",
      "authenticationType": "API_KEY",
      "apiKey": "da2-2ajoq2qmsvgspdw6hljfdj2lb4"

 module Cognito = {
      type authDetailsT;
      type loginT = {
        .
        "_Username": string,
        "_Password": string,
      };
      let authData = (~username: string, ~password: string) : loginT => {
        "_Username": username,
        "_Password": password,
      };
      [@bs.module "aws-sdk"] [@bs.new] [@bs.scope "AmazonCognitoIdentity"]
      external details : loginT => authDetailsT = "AuthenticationDetails";
    };

    module Amplify = {
      type loginT = {
        .
        "_Username": string,
        "_Password": string,
      };
      type loginResultT;
      type loginResult =
        | LoginSuccessful(loginResultT)
        | LoginError
        | LoginChallenge(string);
      [@bs.module "aws-amplify/lib/Auth"] [@bs.scope "default"]
      external configure : 'a => unit = "";
      let configure =
          (
            ~identityPoolId: string,
            ~region: string,
            ~userPoolId: string,
            ~userPoolWebClientId: string,
          ) =>
        configure({
          "Auth": {
            "identityPoolId": identityPoolId,
            "region": region,
            "userPoolId": userPoolId,
            "userPoolWebClientId": userPoolWebClientId,
          },
        });
      [@bs.module "aws-amplify/lib/Auth"] [@bs.scope "default"]
      external signIn : (string, string) => Js.Promise.t('a) = "";
      let signIn = (~username: string, ~password: string) =>
        signIn(username, password)
        |> Js.Promise.then_(result => {
             Js.log(result);
             let challengeName: option(string) =
               result##challengeName |> Js.Nullable.toOption;
             switch (challengeName) {
             | Some(challenge) => Js.log2("Challenge", challenge)
             | None => Js.log("no challenge")
             };
             Js.Promise.resolve(result);
           });
    }; */