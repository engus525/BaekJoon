-- 코드를 작성해주세요
select iii.item_id, iii.item_name, iii.rarity
from item_info ii
join item_tree it on ii.item_id = it.parent_item_id
join item_info iii on it.item_id = iii.item_id
# where ii.item_id = it.parent_item_id and iii.item_id = it.item_id
where ii.rarity like 'RARE'
order by iii.item_id desc