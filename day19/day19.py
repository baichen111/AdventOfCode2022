import re
from collections import deque

pattern = re.compile(r"\d+")

inputs = []
with open("input.txt") as infile:
    lines = infile.readlines()
    for line in lines:
        txt = line.strip()
        data = pattern.findall(txt)
        inputs.append([int(x) for x in data])

#print(inputs)
T = 24

def solve(blueprint):
    _, oreCost, clayCost, ob_OreCost, ob_clayCost, geo_oreCost, geo_obCost = blueprint

    maxOre = oreCost + clayCost + ob_OreCost + geo_oreCost
    maxOre *= 2
    max_clay = max([ob_clayCost])
    max_clay *= 2
    # initial state
    State = (1, 1, 0, 0, 0, 0, 0, 0, 0)
    Q = deque([State])
    visited = {}
    maxGeo = 0
    while Q:
        State = Q.popleft()
        time, oreBots, clayBots, obBots, geoBots, ore, clay, ob, geo = State

        ore = min(ore, maxOre)
        clay = min(clay, max_clay)

        k = (time, oreBots, clayBots, obBots, geoBots)
        v = (ore, clay, ob, geo)

        if k in visited and all(i <= j for i, j in zip(v, visited[k])):
            continue
        if time >= T + 1:
            if geo > maxGeo:
                maxGeo = geo
            continue
        visited[k] = v
        nextState = []

        #build a geode rebot
        if ore >= geo_oreCost and ob >= geo_obCost:
            newState = time+1, oreBots, clayBots, obBots, geoBots + 1, ore-geo_oreCost, clay, ob-geo_obCost, geo
            nextState.append(newState)
        #build an obsidian rebot
        if ore >= ob_OreCost and clay >= ob_clayCost:
            newState = time+1, oreBots, clayBots, obBots + 1, geoBots, ore-ob_OreCost, clay-ob_clayCost, ob, geo
            nextState.append(newState)
        #build a clay rebot
        if ore >= clayCost :
            newState = time+1, oreBots, clayBots + 1, obBots, geoBots, ore-clayCost, clay, ob, geo
            nextState.append(newState)
        #build an ore rebot
        if ore >= oreCost:
            newState = time+1, oreBots + 1, clayBots, obBots, geoBots, ore-oreCost, clay, ob, geo
            nextState.append(newState)

        if ore <= maxOre :
            newState = time+1, oreBots, clayBots, obBots, geoBots, ore, clay, ob, geo
            nextState.append(newState)

        for newState in nextState:
            minutes, oreb, clayb, obb, geob, ore, clay, ob, geo = newState
            Q.append((minutes, oreb, clayb, obb, geob, ore+oreBots,clay+clayBots, ob+obBots, geo+geoBots))

  
    return maxGeo


print(sum((solve(blueprint)* blueprint[0] for blueprint in inputs))) #part1: 2160
