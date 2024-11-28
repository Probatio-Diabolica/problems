def maximumPopulation(logs) -> int:
    popu:list=[0]*2051
    res=0
    for segment in logs:
        popu[segment[0]]+=1
        popu[segment[1]]-=1
    for year in range(1951,2050):
        popu[year]+=popu[year-1]
        if(popu[year]>popu[res]) :res=year
    return res


print(maximumPopulation([[1993,1999],[2000,2010]]))
print(maximumPopulation([[1950,1961],[1960,1971],[1970,1981]]))
