-- Define the top unique salaries per department
WITH salaryTable AS (
    SELECT DISTINCT 
        salary,
        departmentID
    FROM Employee
    ORDER BY departmentID, salary DESC
),
-- Rank salaries within each department and select top 3
newTable AS (
    SELECT 
        *,
        ROW_NUMBER() OVER (PARTITION BY departmentID ORDER BY salary DESC) AS rowNumber
    FROM salaryTable
),
-- Filter for the top 3 salaries in each department
mainTable AS (
    SELECT *
    FROM newTable
    WHERE rowNumber <= 3
),
-- Join top salaries with employee names
a AS (
    SELECT 
        Employee.name AS name, 
        Employee.salary AS salary, 
        Employee.departmentID AS departmentID
    FROM mainTable
    LEFT JOIN Employee ON mainTable.salary = Employee.salary 
                      AND mainTable.departmentID = Employee.departmentID
)

SELECT Department.name as Department, 
        a.name as Employee, 
        a.salary as Salary
FROM (a LEFT JOIN Department
        ON a.departmentId = Department.id);