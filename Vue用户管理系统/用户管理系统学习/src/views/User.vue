<script setup>
import { ref, getCurrentInstance, onMounted, reactive, nextTick } from "vue";
import { ElMessage, ElMessageBox } from "element-plus";
import axios from "axios";

const tableData = ref([]);
const { proxy } = getCurrentInstance();

const getUserData = async () => {
  try {
    const response = await axios.get("http://localhost:6699/userInfo");
    // data.data,数组下的真实数据
    tableData.value = response.data;
    console.log("响应", response.data);
  } catch (error) {
    console.error("获取数据失败", error);
  }
};

const tableLabel = reactive([
  //后端参数传递
  { prop: "name", label: "姓名" },
  { prop: "age", label: "年龄" },
  { prop: "gender", label: "性别" },
  { prop: "birthDate", label: "出生日期", width: 200 },
  { prop: "address", label: "地址", width: 400 },
]);

const formInline = reactive({ keyWord: "" });

const handleSearch = () => {
  config.name = formInline.keyWord;
  getUserData();
};

const config = reactive({
  name: "",
  total: 0,
  page: 1, // Ensure page is initialized
});

const handleChange = (page) => {
  config.page = page;
  getUserData();
};

// const handleDelete = (val) => {
//   ElMessageBox.confirm("确定删除吗?").then(async () => {
//     try {
//       await proxy.$api.deleteUser({ id: val.id });
//       ElMessage({
//         showClose: true,
//         message: "删除成功",
//         type: "success",
//       });
//       getUserData();
//     } catch (error) {
//       ElMessage({
//         showClose: true,
//         message: "删除失败",
//         type: "error",
//       });
//     }
//   });
// };
const handleDelete = (row) => {
  tableData.value = tableData.value.filter((item) => item.id !== row.id);
  // 可选: 同步到服务器
};

// const handleEdit = (val) => {
//   action.value = "edit";
//   dialogVisible.value = true;
//   nextTick(() => {
//     Object.assign(formUser, { ...val, sex: Number(val.sex) });
//   });
// };

const action = ref("add");
const dialogVisible = ref(false);
// const formUser = reactive({});
const formUser = reactive({
  username: "",
  age: "",
  gender: "",
  birthDate: "",
  address: "",
});

const handleAdd = () => {
  dialogVisible.value = true;
  // action.value = "add";
};

const timeFormat = (time) => {
  const date = new Date(time);
  const year = date.getFullYear();
  const month = date.getMonth() + 1;
  const day = date.getDate();
  const add = (m) => (m < 10 ? "0" + m : m);
  return `${year}-${add(month)}-${add(day)}`;
};

// const onSubmit = () => {
//   proxy.$refs["userForm"].validate(async (valid) => {
//     if (valid) {
//       formUser.birth = /^\d{4}-\d{2}-\d{2}$/.test(formUser.birth)
//         ? formUser.birth
//         : timeFormat(formUser.birth);

//       try {
//         let res = null;
//         if (action.value === "add") {
//           res = await proxy.$api.addUser(formUser);
//         } else {
//           res = await proxy.$api.editUser(formUser);
//         }
//         if (res) {
//           dialogVisible.value = false;
//           proxy.$refs["userForm"].resetFields();
//           getUserData();
//         }
//       } catch (error) {
//         ElMessage({
//           showClose: true,
//           message: "操作失败",
//           type: "error",
//         });
//       }
//     } else {
//       ElMessage({
//         showClose: true,
//         message: "请输入正确的内容",
//         type: "error",
//       });
//     }
//   });
// };

const onSubmit = async () => {
  try {
    await axios.post("http://localhost:6699/userInfo/addUser", formUser);
    ElMessage.success("新增成功");
    dialogVisible.value = false;
    // 重新获取数据以更新列表
    await getUserData();
  } catch (error) {
    ElMessage.error("新增失败");
    console.error("新增失败", error);
  }
};
const handleDialogClose = () => {
  // 重置表单数据
  Object.assign(formUser, {
    username: "",
    age: "",
    gender: "",
    birthDate: "",
    address: "",
  });
};

onMounted(() => {
  getUserData();
});
</script>

<template>
  <div class="user-header">
    <el-button type="primary" @click="handleAdd">+新增</el-button>
    <el-form :inline="true" :model="formInline">
      <el-form-item label="请输入">
        <el-input
          placeholder="请输入用户名"
          v-model="formInline.keyWord"
        ></el-input>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" @click="handleSearch">搜索</el-button>
      </el-form-item>
    </el-form>
  </div>
  <div class="table">
    <!-- 显示数据 -->
    <el-table :data="tableData" border style="width: 100%">
      <!-- for循环整合下面注释部分 -->
      <el-table-column
        v-for="item in tableLabel"
        :key="item.prop"
        :width="item.width ? item.width : 125"
        :prop="item.prop"
        :label="item.label"
      ></el-table-column>
      <!-- <el-table-column fixed prop="date" label="日期" width="150">
      </el-table-column>
      <el-table-column prop="name" label="姓名" width="120"> </el-table-column>
      <el-table-column prop="province" label="省份" width="120">
      </el-table-column>
      <el-table-column prop="city" label="市区" width="120"> </el-table-column>
      <el-table-column prop="address" label="地址" width="300">
      </el-table-column>
      <el-table-column prop="zip" label="邮编" width="220"> </el-table-column> -->
      <el-table-column fixed="right" label="操作" width="300">
        <template v-slot="scope">
          <el-button type="text" size="small" @click="handleEdit(scope.row)"
            >编辑</el-button
          >
          <el-button type="text" size="small" @click="handleDelete(scope.row)"
            >删除</el-button
          >
        </template>
      </el-table-column>
    </el-table>
    <!-- 分页操作1.2.3... -->
    <el-pagination
      class="pagediy"
      background
      layout="prev, pager, next"
      :total="config.total"
      @current-change="handleChange"
    >
    </el-pagination>
  </div>

  <!-- 表单的实现 -->
  <el-dialog
    v-model="dialogVisible"
    :title="action === 'add' ? '新增用户' : '编辑用户'"
    width="35%"
    :visible.sync="dialogVisible"
    @before-close="handleDialogClose"
  >
    <!-- 注意：设置了:inline="true"通常不会直接对el-select造成影响，除非有特定的CSS覆盖。这里假设是样式问题，不修改inline属性 -->
    <el-form :inline="true" :model="formUser" :rules="rules" ref="userForm">
      <el-row>
        <el-col :span="12">
          <el-form-item label="姓名" prop="username">
            <el-input v-model="formUser.username" placeholder="请输入姓名" />
          </el-form-item>
        </el-col>
        <el-col :span="12">
          <el-form-item label="年龄" prop="age">
            <el-input v-model.number="formUser.age" placeholder="请输入年龄" />
          </el-form-item>
        </el-col>
      </el-row>
      <el-row>
        <el-col :span="12">
          <el-form-item class="select-clear" label="性别" prop="gender">
            <el-select v-model="formUser.gender" placeholder="请选择">
              <el-option label="男" value="1" />
              <el-option label="女" value="0" />
            </el-select>
          </el-form-item>
        </el-col>
        <el-col :span="12">
          <el-form-item label="出生日期" prop="birthDate">
            <el-date-picker
              v-model="formUser.birthDate"
              type="date"
              placeholder="请输入"
              style="width: 100%"
            />
          </el-form-item>
        </el-col>
      </el-row>
      <el-row>
        <el-form-item label="地址" prop="addr">
          <el-input v-model="formUser.addr" placeholder="请输入地址" />
        </el-form-item>
      </el-row>
      <el-row style="justify-content: flex-end">
        <el-form-item>
          <el-button type="primary" @click="onSubmit">确定</el-button>
          <el-button type="primary" @click="dialogVisible = false"
            >取消</el-button
          >
        </el-form-item>
      </el-row>
    </el-form>
  </el-dialog>
</template>

<style scoped lang="less">
.user-header {
  display: flex;
  justify-content: space-between;
}
.table {
  position: relative;
  height: 520px;
  width: 100%;
  .pagediy {
    position: absolute;
    right: 580px;
    bottom: 30px;
  }
}
.select-clearn {
  display: flex;
}
</style>
