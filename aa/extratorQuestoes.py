import csv
import requests

handle = "gvsl"

url = f"https://codeforces.com/api/user.status?handle={handle}"

data = requests.get(url).json()

solved = {}

for sub in data["result"]:
    if sub["verdict"] == "OK":
        p = sub["problem"]

        if "contestId" in p:
            key = f'{p["contestId"]}{p["index"]}'

            solved[key] = [
                p["contestId"],
                p["index"],
                p["name"],
                sub["creationTimeSeconds"]
            ]

with open("solved.csv","w",newline="",encoding="utf8") as f:
    writer = csv.writer(f)

    writer.writerow(["Contest","Index","Name","FirstAccepted"])

    for row in sorted(solved.values()):
        writer.writerow(row)

print("Exportado!")