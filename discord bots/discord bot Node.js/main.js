const Discord = require('discord.js');

const client = new Discord.Client();

const prefix = '-';

const fs = require('fs');

client.commands = new Discord.Collection();

const commandFiles = fs.readdirSync('./commands/').filter(file => file.endsWith('.js'));
for(const file of commandFiles){
    const command = require(`./commands/${file}`);

    client.commands.set(command.name, command);
}

client.once('ready' , () => {
    console.log('Learnbot is online!');
});

client.on('message', message => {
    if(!message.content.startsWith(prefix) || message.author.bot) return;

    const args = message.content.slice(prefix.length).split(/ +/); // the equal of " "
    const command = args.shift().toLowerCase();

    if(command === 'ping'){
        client.commands.get('ping').execute(message, args);
    } else if (command === 'euroavia'){
        client.commands.get('euroavia').execute(message, args);
    } 
})





client.login('Nzc2MjEyOTcwMDA2NjQyNzE4.X6xmqQ.ze6pP51Q73fD4pAZIK20eDlgaYI');