# Step 0: Create the list of heroes with their gender and power
raw_heroes = [
    ("Thunderclaw", 542137), ("Starblaze", 310982),
    ("Ironvolt", 811530), ("Nightshade", 125674),
    ("Stormwarden", 673892), ("Embermist", 782345),
    ("Voidstrike", 224650), ("Crystalflare", 895321),
    ("Gravitus", 501073), ("Moonveil", 153008),
    ("Blazehound", 660247), ("Sylphara", 47109),
    ("Titanborn", 720905), ("Arcanabelle", 362988),
    ("Riftblade", 346110), ("Lumisera", 588012),
    ("Frostmark", 136089), ("Celestira", 891340),
    ("Dreadcore", 451882), ("Zephyra", 304655),
    ("Magnus Vortex", 703741), ("Virellia", 139204),
    ("Shockflare", 491882), ("Mirage Nova", 828117),
    ("Blackquake", 134760), ("Seraphina Storm", 715993),
    ("Ironhowl", 650210), ("Nebulight", 389443),
    ("Nightcore", 297511), ("Electravine", 811309),
    ("Pyrosurge", 190477), ("Aethera Flux", 479102),
    ("Steelburst", 582694), ("Solandra", 231874),
    ("Phantomwake", 400220), ("Vortexia", 795500),
    ("Venomforge", 282013), ("Quasaria", 129981),
    ("Brimblade", 871307), ("Nyx Warden", 327660),
    ("Onyx Wolf", 177220), ("Glimmerthorn", 492737),
    ("Voltknight", 365198), ("Halocryne", 603443)
]

# Annotate gender based on position: odd -> male, even -> female
heroes = []
for index, (name, power) in enumerate(raw_heroes):
    gender = "Male" if index % 2 == 0 else "Female"
    heroes.append({"name": name, "power": power, "gender": gender, "original_index": index})

# Step 1: Sort heroes by power descending
sorted_heroes = sorted(heroes, key=lambda x: x["power"], reverse=True)

# Step 2: Champion (strongest hero)
champion = sorted_heroes[0]

# Step 3: Filter remaining heroes by gender
remaining_heroes = sorted_heroes[1:]

males = [h for h in remaining_heroes if h["gender"] == "Male"]
females = [h for h in remaining_heroes if h["gender"] == "Female"]

# Step 4: Top 3 males
top_3_males = males[:3]

# Step 5: Top 3 females
top_3_females = females[:3]

# Step 6: 10 weakest remaining heroes (excluding champion + top 3 males + top 3 females)
excluded_names = {champion["name"]} | {h["name"] for h in top_3_males} | {h["name"] for h in top_3_females}
remaining_for_weakest = [h for h in heroes if h["name"] not in excluded_names]
weakest_10 = sorted(remaining_for_weakest, key=lambda x: x["power"])[:10]

# 🧾 Print the results
print("🏆 Champion:")
print(f" - {champion['name']} ({champion['power']})")

print("\n💪 Top 3 Males:")
for h in top_3_males:
    print(f" - {h['name']} ({h['power']})")

print("\n✨ Top 3 Females:")
for h in top_3_females:
    print(f" - {h['name']} ({h['power']})")

print("\n🧹 Weakest 10 Heroes:")
for h in weakest_10:
    print(f" - {h['name']} ({h['power']})")
