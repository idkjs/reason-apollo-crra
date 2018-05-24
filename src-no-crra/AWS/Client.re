open AWS.AppSyncConfig;

let client =
  AWS.AppSync.createAWSAppSyncClient(
    ~url=config##graphqlEndpoint,
    ~region=config##region,
    ~auth={"type": config##authenticationType, "apiKey": config##apiKey},
    (),
  );
/*

 let client =
 createAWSAppSyncClient(
   ~url=config##graphqlEndpoint,
   ~region=config##region,
   ~auth={
     "type": config##authenticationType,
     "apiKey": config##apiKey,
   },
   (),
 );
 */