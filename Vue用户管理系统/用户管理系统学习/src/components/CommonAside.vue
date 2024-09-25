<template>
  <el-aside :width="width">
    <!-- :collapse-transition="false"缩放静态实现 -->
    <el-menu
      background-color="#545c64"
      text-color="#fff"
      :collapse="isCollapse"
      :collapse-transition="false"
      :default-active="activeMenu"
    >
      <h3 v-show="!isCollapse">管理系统学习</h3>
      <h3 v-show="isCollapse">管理</h3>

      <!-- 菜单遍历 -->
      <el-menu-item
        v-for="item in noChildren"
        :index="item.path"
        :key="item.path"
        @click="handleMenu(item)"
      >
        <component class="icons" :is="item.icon"></component>
        <span>{{ item.label }}</span>
      </el-menu-item>

      <!-- 子菜单遍历 -->
      <el-sub-menu
        v-for="item in hasChildren"
        :index="item.path"
        :key="item.path"
      >
        <template #title>
          <component class="icons" :is="item.icon"></component>
          <span>{{ item.label }}</span>
        </template>

        <!-- 二次遍历 -->
        <el-menu-item-group>
          <el-menu-item
            v-for="(subItem, subIndex) in item.children"
            :index="subItem.path"
            :key="subItem.path"
            @click="handleMenu(subItem)"
          >
            <component class="icons" :is="subItem.icon"></component>
            <span>{{ subItem.label }}</span>
          </el-menu-item>
        </el-menu-item-group>
      </el-sub-menu>
    </el-menu>
  </el-aside>
</template>

<script setup>
import { ref, computed } from "vue";
import { useAllDataStore } from "@/stores";
import { useRoute, useRouter } from "vue-router";
const list = computed(() => store.state.menuList);//根据不同用户显示不同菜单
const noChildren = computed(() => list.value.filter((item) => !item.children));
const hasChildren = computed(() => list.value.filter((item) => item.children));
const store = useAllDataStore();
const isCollapse = computed(() => store.state.isCollapse);
const width = computed(() => (store.state.isCollapse ? "64px" : "180px"));
const activeMenu = computed(() => route.path); //刷新后显示选中首页
const route = useRoute();
const router = useRouter();
const handleMenu = (item) => {
  router.push(item.path);
  store.selectMenu(item);
};

</script>

<style lang="less" scoped>
.icons {
  display: inline-block; // 使图标能够与文本并排显示
  vertical-align: middle; // 使图标与文本垂直居中
  width: auto; // 自适应
  height: 18px; // 图标的高度
  margin-right: 8px; // 图标与文本之间的间距
}
.el-menu {
  border-right: none;
  h3 {
    line-height: 48px;
    color: #fff;
    text-align: center;
  }
}
.el-aside {
  height: 100%;
  background-color: #545c64;
}
</style>
