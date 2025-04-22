# 🦸‍♂️🦹‍♀️ Kharavore's List

## 📖 Problem Description

Kharavore, the malevolent warlord from the Tethis Moon, seeks to dominate the universe by defeating Earth’s most powerful heroes.  
To prepare for battle, he devises a plan: clone the mightiest warriors to train against them in a simulated arena.

My mission as a programmer was to help Kharavore by analyzing Earth’s 44 top heroes, selecting:

- 🥇 The strongest hero (Champion)  
- 💪 The top 3 strongest remaining **males**  
- ✨ The top 3 strongest remaining **females**  
- 🧹 The 10 weakest heroes of any gender  

I had to categorize them into separate lists so Kharavore can clone them accordingly.  
This is a basic algorithm and list manipulation exercise created for study purposes.

---

## 🔄 Pseudocode

This is the process I used to solve the problem:

0. I received a list with all 44 heroes and their respective power levels.  
   Odd-numbered entries are male heroes, and even-numbered entries are female heroes.
1. I sorted the list in descending order by power level.
2. I added the first (strongest) hero to the Champion list.
3. I filtered the remaining heroes by gender using the odd/even position in the original list.
4. From the filtered male list, I selected the 3 strongest and added them to a new list.
5. From the filtered female list, I selected the 3 strongest and added them to another list.
6. From the remaining heroes, I selected the 10 weakest and added them to the Losers list.

---

## 🧠 Implementation and Results

The result was an algorithm capable of solving the problem efficiently—saving my neck from Kharavore’s wrath.  
It was implemented in Python and C++, the two languages I am currently studying the most.
