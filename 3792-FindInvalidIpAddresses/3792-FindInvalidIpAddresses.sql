-- Last updated: 20/07/2026, 10:42:37
# Write your MySQL query statement below

select ip, count(*) as invalid_count
from logs
where
    length(ip) - length(replace(ip, '.', '')) != 3
    or ip regexp '[^0-9.]'
    or ip regexp '(^|\\.)0[0-9]'
    or ip regexp '(^|\\.)([3-9][0-9]{2,}|2[6-9][0-9]|25[6-9])'
group by ip
order by invalid_count desc, ip desc;