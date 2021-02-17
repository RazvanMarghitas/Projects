import discord
# import random
# import smtplib

# with smtplib.SMTP('smtp.gmail.com',25) as smtp:
#     smtp.ehlo()
#     smtp.starttls()
#     smtp.ehlo()

#     smtp.login("gmail","pass")

# from email.message import EmailMessage
from discord.ext import commands

client = discord.Client()
bot = commands.Bot(command_prefix = '-')
# suggestion_channel_id = 783308696192811048
welcome_channel_id = 777637547400364043



@bot.event
async def on_ready():
    print('Bot is ready.')

@bot.command()
async def ping(ctx):
    await ctx.send(f'Pong! {round(bot.latency*1000)} ms')

# @bot.command(aliases=['8ball'])
# async def _8ball(ctx, *, question):
#     responses = ['yes','no','maybe','idk']
#     await ctx.send(f'Qestion: {question}\nAnswer: {random.choice(responses)}')

# @bot.event
# async def on_member_join(member):
#     print(f'{member} has joined the server.')

# @bot.command()
# async def clear(ctx, amount=5):
#     await ctx.channel.purge(limit=amount)

# @bot.command()
# async def kick(ctx, member: discord.Member, *, reason=None):
#     await member.kick(reason=reason)

# @bot.command()
# async def ban(ctx, member: discord.Member, *, reason=None):
#     await member.ban(reason=reason)
#     await ctx.send(f'Banned {member.mention}')

# @bot.command()
# async def unban(ctx, *, member):
#     banned_users = await ctx.guild.bans()
#     member_name, member_discriminator = member.split('#')

#     for ban_entry in banned_users:
#         user = ban_entry.user

#         if (user.name, user.discriminator) == (member_name, member_discriminator):
#             await ctx.guild.unban(user)
#             await ctx.send(f'Unbanned {user.mention}')
#             return

# @bot.event
# async def  on_raw_reaction_add(payload):
#     if payload.channel_id == suggestion_channel_id:
#         if payload.emoji.name == "👍":
#             channel = bot.get_channel(suggestion_channel_id)
#             message = await channel.fetch_message(payload.message_id)
#             reactionlist = message.reactions
#             for reaction in reactionlist:
#                 if reaction.emoji == '👍':
#                     reactionnr = reaction.count
#                 break
#             if reactionnr == 15 and not message.pinned :
#                 await message.pin()

@bot.command()
@commands.has_permissions(ban_members=True)
async def inv(ctx, a:int):
    # msg = EmailMessage()
    welcome_channel = bot.get_channel(welcome_channel_id)
    invlink = await welcome_channel.create_invite(max_age=0,max_uses = a, temporary = False)
    await ctx.send(f'Hello,\n\nHere are the invites for the euroavia discord server {invlink} for a total of {a} uses.\n\nHave a great day,\nIB!')
    # msg.set_content(f'Hello,\nHere are the invites for the euroavia discord server\n{invlink} for a total of {a} uses\n Have a great day,\n IB!')
    # msg['Subject'] = 'Invites for discord'
    # msg['From'] = 'razvan.marghitas@euroavia.eu'
    # msg['To'] = email
    # smtp.connect()
    # smtp.send_message(msg)
    # smtp.quit()


bot.run('token')
