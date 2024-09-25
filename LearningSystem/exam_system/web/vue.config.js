module.exports = {
    chainWebpack: config =>{
        config.plugin('html')
            .tap(args => {
                args[0].title = "AutoLearnSystem";
                args[0].keywords = "AutoLearnSystem";
                args[0].description = "AutoLearnSystem";
                return args;
            })
    },
};
