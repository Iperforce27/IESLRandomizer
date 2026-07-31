from tkinter import *
import random

#turn txt files into lists
GKs = open("GKs.txt", "r")
DFs = open("DFs.txt", "r")
MFs = open("MFs.txt", "r")
FWs = open("FWs.txt", "r")
MGs = open("MGs.txt", "r")
COs = open("COs.txt", "r")

GK_list = GKs.readlines() 
DF_list = DFs.readlines()
MF_list = MFs.readlines()
FW_list = FWs.readlines()
CO_list = COs.readlines() 
MG_list = MGs.readlines()

GKs.close()
DFs.close()
MFs.close()
FWs.close()
MGs.close()
COs.close()


playerList = [] #List of players extracted
staffList = []  #List of coach and manager extracted
DFnumb = None   #Number of defenders to extract
MFnumb = None   #Number of midfielders to extract
FWnumb = None   #Number of forwards to extract

#Add a random player to the team
def GetRandomPlayer(list):
    index = random.randrange(len(list)-1)
    while list[index] in playerList:
        index = random.randrange(len(list)-1)
    playerList.append(list[index])

#Add a random staff member
def GetRandomStaff(list):
    index = random.randrange(len(list)-1)
    staffList.append(list[index])

#Randomize the team
def Randomize(DFn, MFn, FWn):
    GetRandomPlayer(GK_list)
    for i in range(DFn):
        GetRandomPlayer(DF_list)
    for i in range(MFn):
        GetRandomPlayer(MF_list)
    for i in range(FWn):
        GetRandomPlayer(FW_list)
    GetRandomStaff(CO_list)
    GetRandomStaff(MG_list)

#Show the randomized team in a new window
def PrintTeam():
    #Make a string with the team list
    team = f'Players:\n'    #Team list string
    for i in playerList:
        team = team + i
    team = team + f'\nStaff:\n'
    for i in staffList:
        team = team + i

    #Make a top level window with the team list
    teamPage = Toplevel(root)
    teamPage.title("Your team")
    showTeam = Text(teamPage)
    showTeam.pack()
    showTeam.insert(END, team)
    showTeam.config(state="disabled")
    teamPage.mainloop()

#design window
root = Tk()
root.title("IESL Randomizer")
root.geometry("400x300")

titleLabel = Label(root, text="IESL Randomizer (made by Iper)", height=2).pack()
introLabel = Label(root, text="Welcome to the IESL Randomizer!").pack(anchor='w')
instructionLabel = Label(root, text="Input the formation").pack(anchor='w')

inputFrame = Frame(root)
DFlabel = Label(inputFrame, text="Defenders:").grid(row=0,column=0)
MFlabel = Label(inputFrame, text="Midfielders:").grid(row=1,column=0)
FWlabel = Label(inputFrame, text="Forwards:").grid(row=2,column=0)
DFnumb_var = IntVar(inputFrame)
MFnumb_var = IntVar(inputFrame)
FWnumb_var = IntVar(inputFrame)
DFinput = Entry(inputFrame, textvariable=DFnumb_var).grid(row=0, column=1)
MFinput = Entry(inputFrame, textvariable=MFnumb_var).grid(row=1, column=1)
FWinput = Entry(inputFrame, textvariable=FWnumb_var).grid(row=2, column=1)
inputFrame.pack(anchor='w')

#Start the randomization
def StartRandomize():
    playerList.clear()
    staffList.clear()
    DFnumb = DFnumb_var.get()
    MFnumb = MFnumb_var.get()
    FWnumb = FWnumb_var.get()
    Randomize(DFnumb, MFnumb, FWnumb)
    PrintTeam()
    


randomizeButton = Button(root, text="Randomize!", background="Orange", command=StartRandomize).pack(anchor="w")
root.mainloop()

