
module.exports = {
    name: 'euroavia',
    description: "send euroavia link!",
    execute(message, args){


        // let role = message.guild.roles.cache.find(r => r.name === 'Model');

        // if(message.member.permissions.has("BAN_MEMBERS")){
        //     message.channel.send('You have the permission to ban members');
        // } else {
        //     message.channel.send('You dont have the permission to ban members');
        // }



        // if(message.member.roles.cache.some(r => r.name === "Model")){

        //     message.channel.send('https://euroavia.eu');

        // }else {
        //     message.channel.send('You dont have the correct permissions, take em!'); //use nothing here preferably
        //     message.member.roles.add(role).catch(console.error);
        // }

        message.channel.send('https://euroavia.eu');

        
    }
}