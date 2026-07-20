-- Last updated: 20/07/2026, 11:26:04
# Write your MySQL query statement below

select teacher_id, count(distinct subject_id) as cnt from teacher group by teacher_id