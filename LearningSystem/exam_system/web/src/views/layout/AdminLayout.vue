<template>
  <el-container style="height: 100%">
    <el-aside
      width="200px"
      style="background-color: #554a55; overflow-x: hidden"
      class="aside-background"
    >
      <h3 class="title">Prison Break</h3>
      <!-- 图标更换    https://element.eleme.cn/#/zh-CN/component/icon-->
      <el-menu
        class="custom-menu"
        :default-openeds="['']"
        router
        style="border: none; background-color: transparent"
        :default-active="$route.path"
      >
        <el-menu-item
          v-for="(item, i) in roleMenu"
          v-show="!item.isPage"
          :key="i"
          :index="item.path"
          ><i :class="item.iconClass"></i
          ><span slot="title">{{ item.title }}</span></el-menu-item
        >
        <el-submenu
          index="user"
          v-for="item in roleMenu"
          v-show="item.isPage"
          :key="item.name"
        >
          <template slot="title">
            <i class="el-icon-s-home"></i><span>{{ item.title }}</span>
          </template>
          <el-menu-item
            v-for="(current, index) in item.list"
            :key="index"
            :index="current.path"
          >
            <i :class="current.iconClass"></i
            ><span slot="title">{{ current.title }}</span></el-menu-item
          >
        </el-submenu>
      </el-menu>
    </el-aside>
    <el-container>
      <el-header
        style="
          text-align: right;
          font-size: 12px;

        "
      >
        <el-avatar
          style="
            width: 40px;
            height: 40px;
            position: relative;
            top: 12px;
            right: 10px;
          "
          shape="circle"
          :size="30"
          :src="userInfo.img"
        ></el-avatar>
        <el-dropdown>
          <span class="el-dropdown-link">
            {{ userInfo.username
            }}<i class="el-icon-arrow-down el-icon--right"></i>
          </span>
          <el-dropdown-menu slot="dropdown">
            <el-dropdown-item
              ><span @click="editUserInfo">个人信息</span></el-dropdown-item
            >
            <el-dropdown-item
              ><span @click="editPassword">修改密码</span></el-dropdown-item
            >
            <el-dropdown-item divided
              ><span @click="logout">退出登录</span></el-dropdown-item
            >
          </el-dropdown-menu>
        </el-dropdown>
      </el-header>
      <el-main>
        <router-view />
      </el-main>
    </el-container>
  </el-container>
</template>
<script>
import tools from "@/utils/utils";

export default {
  data() {
    return {
      userInfo: tools.getUserInfo(),
      roleMenu: [],
    };
  },
  created() {},
  mounted() {
    this.roleMenu = tools.getRoleMenu();
  },
  methods: {
    logout() {
      this.$message({
        message: "退出登录成功，正在跳转",
        type: "success",
      });
      localStorage.removeItem("systemUser");
      localStorage.removeItem("systemRoleMenu");
      setTimeout(() => {
        this.$router.push({ path: "/login" });
      }, 1000);
    },
    editUserInfo() {
      this.$router.push({ path: "/editUserInfo" });
    },
    editPassword() {
      this.$router.push({ path: "/editPassword" });
    },
  },
};
</script>

<style>
.el-header {
  /* background-color: #d9dbde; */
  line-height: 60px;
  background-image: url('../../assets/car.jpg');
  background-size: cover;
}

.aside-background {
  background-image: url("../../assets/jcole.png");
}
.menu-item {
  background-color: transparent !important; /* 设置为透明，继承背景 */
}

/* 修改菜单项的字体颜色 */
.custom-menu .el-menu-item,
.custom-menu .el-submenu__title {
  color: rgb(212, 212, 227); /* 设置为白色 */
  /* 你还可以添加其他样式，如字体大小、字体家族等 */
}

/* 如果你还想修改激活状态的菜单项颜色 */
.custom-menu .el-menu-item.is-active,
.custom-menu .el-submenu.is-active .el-submenu__title {
  color: #0b0b0b; /* 激活状态的颜色 */
  background-color: #caddf1;
}

/*更改下拉框的样式*/
.el-dropdown-link {
  cursor: pointer;
  color: #409eff;
}

.el-icon-arrow-down {
  font-size: 12px;
}

.title {
  text-align: center;
  color: #fff;
  height: 30px;
  line-height: 30px;
  margin-top: 11px;
}
/*搜索框大小定义*/
.input {
  width: 200px !important;
  margin-right: 10px;
}

.mr10px {
  margin-right: 10px;
}

.pb10px {
  padding-bottom: 10px;
}
.el-main{
  background-image: url('../../assets/Christmas.jpg');
  background-size: cover; /* 使背景图片覆盖整个容器 */
  background-position: center; /* 将背景图片居中 */
  /* 可以根据需要添加其他样式，如padding、margin等 */
}
</style>
