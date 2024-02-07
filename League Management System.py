import csv

class TeamManager:
    def __init__(self):
        self.teams = []

    def registerTeam(self, team_name, players):
        club = {
               "Name" : team_name,
               "Players" : players
            }

        self.teams.append(club)

    def displayTeamInfo(self, team_name):
        for team in self.teams:
            if team["Name"] == team_name:
                print("Team Name:", team_name)
                print("Players:")
                for player in team["Players"]:
                    print(player)

class MatchDay:
    def __init__(self):
        self.matches = []

    def schedulematch(self, team1, team2, date, location):
        match = {
                "Home" : team1,
                "Away" : team2,
                "Date" : date,
                "Stadium" : location
            }
        self.matches.append(match)

        self.savematches("C:\\Users\\Alist\\Desktop\\matches.csv")

    def display_schedule(self):
        for game in self.matches:
            for key, value in game.items():
                print(f"{key}: {value}")

    def savematches(self, file):
        column_names = self.matches[0].keys()
        with open(file, 'w', newline='') as savedfile:
            writer = csv.DictWriter(savedfile, column_names)
            writer.writeheader()
            writer.writerows(self.matches)
        

class PlayerStatistics:
    def __init__(self):
        self.playerStatistics = []

    def recordStats(self, player_name, goals, assists, yellow_cards, red_cards):
        ps = {
            "Name":player_name,
            "Goals":goals,
            "Assists":assists,
            "Yellow Cards":yellow_cards,
            "Red Cards":red_cards
             }
        
        self.playerStatistics.append(ps)

    def displayPlayerStats(self, playerName):
        for i in self.playerStatistics:
            if i["Name"] == playerName:
                for key, value in i.items():
                    print(f"{key}: {value}")

class MatchReader:
    def __init__(self, file_path, delimiter=','):
        self.file_path = file_path
        self.delimiter = delimiter
        self.matches = self.readCSV()

    def readCSV(self):
        matches = []
        with open(self.file_path, 'r') as file:
            reader = csv.reader(file, delimiter=self.delimiter)
            header = next(reader)
            for row in reader:
                
                team1 = row[4]
                team2 = row[5]
                date = row[1]
                stadium = row[65]

                if team1 == 'Arsenal' or team2 == 'Arsenal':
                    match = {
                        "Home": team1,
                        "Away": team2,
                        "Date": date,
                        "Stadium": stadium
                    }
                
                    matches.append(match)
        return matches
        
file_path = "C:\\Users\\Alist\\Downloads\\england-premier-league-matches-2018-to-2019-stats.csv"

schedule_reader = MatchReader(file_path, delimiter=',')

for clubs in schedule_reader.matches:
    print(clubs)


gmwk1 = MatchDay()

gmwk1.schedulematch("Arsenal", "Spurs", "7/12/2023", "Emirates")
"""
gmwk1.display_schedule()

data = PlayerStatistics()

team_manager = TeamManager()

team_manager.registerTeam("Arsenal", ["Jesus", "Odegaard", "Sako"])

team_manager.displayTeamInfo("Arsenal")

data.recordStats("Odegaard", 2, 1, 1, 0)

data.recordStats("Giroud", 2, 0, 1, 0)

data.displayPlayerStats("Odegaard")
"""
