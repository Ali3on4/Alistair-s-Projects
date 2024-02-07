import random

class Player:
    def __init__(self, name, position, skillLevel):
        self.name = name
        self.skillLevel = skillLevel
        self.position = position
    def __str__(self):
        return f"Name: (self.name) |  SkillLevel: (self.skillLevel) | Position: (self.position)"

class Goalkeeper(Player):
    def __init__(self, name, position, goalkeeperAbility):
        skillLevel = goalkeeperAbility
        Player.__init__(self, name, position, skillLevel)
        self.GKSkill = goalkeeperAbility
        
        
class FieldPlayer(Player):
    def __init__(self, name, position, dribble, passing, shooting, defending):
        skillLevel = (dribble + passing + shooting + defending) / 4
        Player.__init__(self, name, position, skillLevel)
        self.dribbleStat = dribble
        self.passingStat = passing
        self.shootingStat = shooting
        self.defendingStat = defending

class Team:
    def __init__(self, name):
        self.name = name
        self.players = []
        self.goals = 0
        self.teamSkill = 0

    def addPlayer(self, p):
        self.players.append(p)

    def viewplayer(self):
        for Player in self.players:
            print(Player.name, Player.skillLevel, Player.position)
    

    def avgSkill(self):
        skLvltotal = []
        
        for Player in self.players:
            skLvltotal.append(Player.skillLevel)
            
        self.teamSkill = sum(skLvltotal) / 11
        print("The average score of the team is: ", self.teamSkill)

    def bestlineup(self):
        defenders = 0
        midfielders = 0
        attackers = 0
        formation = []

        for player in self.players:
            if player.position == "CB" or player.position == "RB" or player.position == "LB" or player.position == "LWB" or player.position == "RWB":

                player.position = "DEF"
                defenders += 1
                
            elif player.position == "CDM" or player.position == "CM" or player.position == "CAM" or player.position == "RM" or player.position == "LM":

                player.position = "MID"
                midfielders += 1
                
            elif player.position == "CF" or player.position == "ST" or player.position == "RW" or player.position == "LW":

                player.position = "ATT"
                attackers += 1

        formation.append(defenders)
        formation.append(midfielders)
        formation.append(attackers)

        print(formation)
        
    def __str__(self):
        return f"Name: (self.name)|  Players: (self.players) | GS: (self.goals)  |  Teamskill: (self.teamSkill)"


"""
Gamestate(Team):
    def ___init___(self, stateAttack, stateDefence, stateMiddle, eventTimer):
        self.stateAttack = Attack
        self.stateDefence = Defence
        self.stateMiddle = Middle
        self.eventTimer = Gameminute
"""

def randomizerattplayer(attackingTeam):

    numberofattackingplys = 0
        
    attackingplayers = []
        
    for player in attackingTeam.players:
        if player.position == "ATT":
            attackingplayers.append(player.name)
            numberofattackingplys += 1

    playerwhoscored = random.randint(0, numberofattackingplys)
    
    return attackingplayers[playerwhoscored - 1]


def randomizerdefplayer(defendingTeam):

    numberofdefenseplys = 0

    defendingplayers = []

    for player in defendingTeam.players:
        if player.position == "DEF":
            defendingplayers.append(player.name)
            numberofdefenseplys += 1

    playerwhosaved = random.randint(0, numberofdefenseplys)

    return defendingplayers[playerwhosaved - 1]



def MidfieldPhase(attackingTeam, defendingTeam):

    attackingplayers = []
    defendingplayers = []

    totalAttacking = 0
    totalDefending = 0
    totalDribblingplusPassing = 0

    for player in attackingTeam.players:
        if player.position == "MID":
            attackingplayers.append(player)
            totalAttacking += player.skillLevel

    for player in defendingTeam.players:
        if player.position == "MID":
            defendingplayers.append(player)
            totalDefending += player.skillLevel

    playerdiff = totalAttacking - totalDefending
    teamdifference = attackingTeam.teamSkill - defendingTeam.teamSkill

    overalldiff = playerdiff + teamdifference

    if overalldiff >= 6:
        chancemeter = 8
        AttackPhase(attackingTeam, defendingTeam, chancemeter)
    elif overalldiff >= 4 and overalldiff < 6:
        chancemeter = 10
        AttackPhase(attackingTeam, defendingTeam, chancemeter)
    elif overalldiff >= 0 and overalldiff < 4:
        chancemeter = 12
        AttackPhase(attackingTeam, defendingTeam, chancemeter)
    elif overalldiff <= 0:
        chancemeter = 13
        AttackPhase(attackingTeam, defendingTeam, chancemeter)


def AttackPhase(attackingTeam, defendingTeam, chanceMeter):
    attackingplayers = []
    defendingplayers = []

    totalAttacking = 0
    totalDefending = 0

    for player in attackingTeam.players:
        if player.position == "ATT":
            attackingplayers.append(player)
            totalAttacking += player.skillLevel

    for player in defendingTeam.players:
        if player.position == "DEF":
            defendingplayers.append(player)
            totalDefending += player.skillLevel

    diff = totalAttacking - totalDefending
    
    
    if diff > 0:
        if diff <= 1:
            scoringProbability = random.randint(1,chanceMeter)
            if scoringProbability <= 3:
                attackingTeam.goals += 1
                print(randomizerattplayer(attackingTeam)," has just scored!")
            else:
                print(randomizerdefplayer(defendingTeam)," with an excellent defensive action!")
        elif diff <= 1.50 or diff > 1:
            scoringProbability = random.randint(1,chanceMeter)
            if scoringProbability <= 4:
                attackingTeam.goals += 1
                print(randomizerattplayer(attackingTeam)," has just scored!")
            else:
                print(randomizerdefplayer(defendingTeam)," with an excellent defensive action!")
    elif diff < 0:
        scoringProbability = random.randint(1,chanceMeter)
        if scoringProbability <= 3:
            attackingTeam.goals += 1
            print(randomizerattplayer(attackingTeam)," has just scored!")
        else:
            print(randomizerdefplayer(defendingTeam)," with an excellent defensive action!")
                
                
Team1 = Team("Team1")
Team2 = Team("Team2")
    
events = 0

print("______________________________________________________________")
print("|                                                             |")
print("|                   Alistairs Game Simulator                  |")
print("|_____________________________________________________________|")

print("")
print("")

print("Let's begin by adding players to the teams and allocating their stats")
print("Player 1 can pick his team first")

players1added = 2
players2added = 2

Goalkeeperna = input("Lets start off with the goalkeeper, who is that going to be?: ")
gkpos = "GK"
GoalkeeperSkill = int(input("Please provide the goalkeeping ability statistic out of 10: "))
goalkeeper = Goalkeeper(Goalkeeperna, gkpos, GoalkeeperSkill)
Team1.addPlayer(goalkeeper)

while players1added <= 11:
    
    print("Entering player number:", players1added)
    playerName = input("The name of your player: ")
    playerPos = input("Please provide the position of this player: ")
    playerdribbling = int(input("Please provide the dribbling statistic out of 10: "))
    playerpassing = int(input("Please provide the passing statistic out of 10: "))
    playershooting = int(input("Please provide the shooting statistic out of 10: "))
    playerdefending = int(input("Please provide the defending statistic out of 10: "))

    player = FieldPlayer(playerName, playerPos, playerdribbling, playerpassing, playershooting, playerdefending)
    
    Team1.addPlayer(player)
    players1added += 1
    
Team1.bestlineup()
print("Users 1 Team: ")
Team1.viewplayer()
Team1.avgSkill()

print("")
print("")
print("Now onto User 2s team")

Goalkeeperna2 = input("Lets start off with the goalkeeper, who is that going to be?: ")
gkpos2 = "GK"
GoalkeeperSkill2 = int(input("Please provide the goalkeeping ability statistic out of 10: "))
goalkeeper2 = Goalkeeper(Goalkeeperna2, gkpos2, GoalkeeperSkill2)
Team2.addPlayer(goalkeeper2)

while players2added <= 11:
    
    print("Entering player number:", players2added)
    playerName = input("The name of your player: ")
    playerPos = input("Please provide the position of this player: ")
    playerdribbling = int(input("Please provide the dribbling statistic out of 10: "))
    playerpassing = int(input("Please provide the passing statistic out of 10: "))
    playershooting = int(input("Please provide the shooting statistic out of 10: "))
    playerdefending = int(input("Please provide the defending statistic out of 10: "))

    player = FieldPlayer(playerName, playerPos, playerdribbling, playerpassing, playershooting, playerdefending)
    
    Team2.addPlayer(player)
    players2added += 1

Team2.bestlineup()
print("Users 2 Team: ")
Team2.viewplayer()
Team2.avgSkill()

timebeginning = 0
timeend = 10

while events != 10:

    firstteamevent = random.randint(timebeginning, timeend)
    print(firstteamevent)
    MidfieldPhase(Team1, Team2)
    input("Press enter to continue")
    secondteamevent = random.randint(timebeginning, timeend)
    while secondteamevent < firstteamevent:
        if secondteamevent >= firstteamevent:
            break
        else:
            secondteamevent = random.randint(timebeginning, timeend)
    print(secondteamevent)
    MidfieldPhase(Team2, Team1)
    input("Press enter to continue")
    events += 1
    timebeginning += 10
    timeend += 10

print("The final scoreline is Team 1: ", Team1.goals, "Team 2: ", Team2.goals)
    
