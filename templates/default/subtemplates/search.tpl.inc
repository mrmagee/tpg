{include file="$template/subtemplates/ajax_preview.tpl.inc"}
<script type="text/javascript">/* <![CDATA[ */
function ap(id)
{literal}{{/literal}
document.write(' <a href="#" onclick="ajax_preview('+id+'); return false" title="{#ajax_preview_title#|escape:"quotes"}" onfocus="this.blur()"><img class="ap" src="templates/{$settings.template}/images/ajax_preview.png" title="{#ajax_preview_title#|escape:"quotes"}" alt="[…]" width="11" height="11" /><\/a>');
{literal}}{/literal}
/* ]]> */</script>

<form action="index.php" method="get" accept-charset="{#charset#}">
<div style="margin-bottom:20px;">
<input type="hidden" name="mode" value="search" />
<input type="text" name="search" value="{$search|default:""}" size="30" />
{if $categories}
<select size="1" name="p_category">
<option value="0"{if $category==0} selected="selected"{/if}>{#all_categories#}</option>
{foreach key=key item=val from=$categories}
{if $key!=0}<option value="{$key}"{if $key==$p_category} selected="selected"{/if}>{$val}</option>{/if}
{/foreach}
</select>
{/if}
<input type="submit" name="search_submit" value="{#search_submit_button#}" />{if $settings.tags>0}<br />
<span class="small"><input id="searchfulltext" type="radio" name="method" value="0"{if $method == 'fulltext'} checked="checked"{/if} /><label for="searchfulltext">{#search_fulltext#}</label> <input id="searchtags" type="radio" class="search-radio" name="method" value="tags"{if $method == 'tags'} checked="checked"{/if} /><label for="searchtags">{#search_tags#}</label></span>{/if}
</div></form>
{if $search}
{if $search_results}
<p>{if $search_results_count>1}{$smarty.config.several_postings_found|replace:"[number]":$search_results_count}{else}{#one_posting_found#}{/if}</p>
<ul class="searchresults">
{section name=result loop=$search_results}
<li><a class="{if $search_results[result].pid==0}thread-search{else}reply-search{/if} {if $visited && in_array($search_results[result].id,$visited)} visited{/if}" href="index.php?id={$search_results[result].id}">{$search_results[result].subject}</a>{if $search_results[result].no_text}<span><strong>*</strong></span>{/if} - <strong>{$search_results[result].name}</strong>, {$search_results[result].formated_time}<script type="text/javascript">/* <![CDATA[ */ ap({$search_results[result].id}); /* ]]> */</script> <a href="index.php?mode=thread&amp;id={$search_results[result].id}" title="{#open_whole_thread#}"><img src="templates/{$settings.template}/images/complete_thread.png" alt="{#open_whole_thread#}" width="11" height="11" /></a> {if $search_results[result].category}<a href="index.php?mode=index&amp;category={$search_results[result].category}"><span class="category">({$search_results[result].category_name})</span></a>{/if}</li>
{/section}
</ul>
{if $page_browse && $page_browse.total_items > $page_browse.items_per_page}
<p>
{if $page_browse.previous_page!=0}
<a href="index.php?mode={$mode}{if $action}&amp;action={$action}{/if}{if $search_encoded}&amp;search={$search_encoded}{/if}{if $method && $method!='fulltext'}&amp;method={$method}{/if}{if $id}&amp;id={$id}{/if}{if $page_browse.previous_page>1}&amp;page={$page_browse.previous_page}{/if}{if $p_category && $p_category>0}&amp;p_category={$p_category}{/if}{if $order}&amp;order={$order}{/if}{if $descasc}&amp;descasc={$descasc}{/if}">&laquo;</a>
{/if}
{section name=x loop=$page_browse.browse_array}
{if $page_browse.browse_array[x]==$page_browse.page}
<span style="color:red;">{$page_browse.browse_array[x]}</span>
{elseif $page_browse.browse_array[x]==0}
..
{else}
<a href="index.php?mode={$mode}{if $action}&amp;action={$action}{/if}{if $search_encoded}&amp;search={$search_encoded}{/if}{if $method && $method!='fulltext'}&amp;method={$method}{/if}{if $id}&amp;id={$id}{/if}{if $page_browse.browse_array[x]>1}&amp;page={$page_browse.browse_array[x]}{/if}{if $p_category && $p_category>0}&amp;p_category={$p_category}{/if}{if $order}&amp;order={$order}{/if}{if $descasc}&amp;descasc={$descasc}{/if}">{$page_browse.browse_array[x]}</a>
{/if}
{/section}
{if $page_browse.next_page!=0}
<a href="index.php?mode={$mode}{if $action}&amp;action={$action}{/if}{if $search_encoded}&amp;search={$search_encoded}{/if}{if $method && $method!='fulltext'}&amp;method={$method}{/if}{if $id}&amp;id={$id}{/if}&amp;page={$page_browse.next_page}{if $p_category && $p_category>0}&amp;p_category={$p_category}{/if}{if $order}&amp;order={$order}{/if}{if $descasc}&amp;descasc={$descasc}{/if}">&raquo;</a>
{/if}
</p>
{/if}
{else}
<p>{#no_postings_found#}</p>
{/if}
{/if}

