# Gigel_route

Problem source: http://www.infoarena.ro/problema/traseu

Gigel moved to a new city! To get acquainted with the new surroundings, he bought the city map and noticed that it is made up of M directed streets of different lengths and N intersections of streets. Gigel took the map and began building a route starting from a specific intersection, passing through each street at least once, and returning to the intersection where it started. Although his desire for exploration is great, his physical condition is not good, so he wants to find a route where the sum of the lengths of the streets traveled is minimal. A program is required for that.

Input: On the first line of the trail file you find the N and M numbers separated by a space. On the following M lines you will find triplets of numbers i j k with the meaning that there is a street from the intersection with the number i and the intersection with number j of length k.

Output: The first line of the route.out file will display a single natural number representing the minimum length of Gigel's route.

Restrictions:
	→ 1 ≤ N ≤ 60
	→ Street lengths are natural numbers ranging from [1, 10,000]
	→ If between two intersections i and j there is a street, then with loneliness there will not be a 	street and between intersections j and i
	→ It is guaranteed that there is at least one route in the city that passes through each street at 	least once and starts and ends at the same intersection
