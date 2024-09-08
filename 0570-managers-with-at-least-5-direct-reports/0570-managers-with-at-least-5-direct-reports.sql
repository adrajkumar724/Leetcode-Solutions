# Write your MySQL query statement below
select e1.name 
from Employee e1
INNER  JOIN 
Employee e2
ON e1.id=e2.managerId
GROUP BY e2.managerId having count(e2.managerId)>=5