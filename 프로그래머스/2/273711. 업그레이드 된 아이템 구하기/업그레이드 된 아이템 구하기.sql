-- 코드를 작성해주세요
select iii.item_id, iii.item_name, iii.rarity
from item_info ii, item_info iii, item_tree it
where ii.item_id = it.parent_item_id and iii.item_id = it.item_id
and ii.rarity like 'RARE'
# and ii.rarity in
# (
#     select rarity
#     from item_info
#     where rarity like 'RARE'
# )
order by iii.item_id desc