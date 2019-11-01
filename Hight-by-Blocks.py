
def exLim(lim, list):
    if lim != -1:
        for itm in list:
            if (list[itm]) > lim:
                return True
    return False

pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989"
colors = {
    0:"Black",
    1:"Brown",
    2:"Red",
    3:"Orange",
    4:"Yellow",
    5:"Green",
    6:"Blue",
    7:"Violet",
    8:"Gray",
    9:"White"
    }

count = {
    "Black":0,
    "Brown":0,
    "Red":0,
    "Orange":0,
    "Yellow":0,
    "Green":0,
    "Blue":0,
    "Violet":0,
    "Gray":0,
    "White":0
    }

dx = 0.944882
xi = 0
i=0

tgt = int(input("Target Height (ft): "))*12
lim = int(input("Block Limit, \"-1\" to ignore: "))

while xi+dx <= tgt and not exLim(lim,count):
    dig = pi[i]
    #print(colors.get(int(dig)))
    count[colors.get(int(dig))] = count[colors.get(int(dig))] +1
    xi = xi + dx
    i = i+1

if xi+dx >= tgt:
    print("\nEnd Condition: Hight")
else:
    print("\nEnd Condition: Block Count")

print("Height: " + str(xi/12))
print("Block Count: " + str(count))